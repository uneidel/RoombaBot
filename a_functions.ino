void LoadSetup(){
if (SPIFFS.begin()) {
    Serial.println("mounted file system");
    if (SPIFFS.exists("/config.json")) {
      //file exists, reading and loading
      Serial.println("reading config file");
      File configFile = SPIFFS.open("/config.json", "r");
      if (configFile) {
        Serial.println("opened config file");
        size_t size = configFile.size();
        // Allocate a buffer to store contents of the file.
        std::unique_ptr<char[]> buf(new char[size]);

        configFile.readBytes(buf.get(), size);
        DynamicJsonBuffer jsonBuffer;
        JsonObject& json = jsonBuffer.parseObject(buf.get());
        json.printTo(Serial);
        if (json.success()) {
          strcpy(mqtt_server, json["mqtt_server"]);                  
        } 
        else {
          Serial.println("failed to load json config");
        }
      }
    }
  } else {
    Serial.println("failed to mount FS");
  }
  
}
void setupIR() 
{
  
 pinMode(5, OUTPUT);
  digitalWrite(5, HIGH);
}

void setupNTP(){
  Serial.println("Connect NTP");
  NTP.begin("0.de.pool.ntp.org", 1, true);
  NTP.setInterval(63);
  
}
char * ConvertfloatString(float Value) {
     char charBuf[10];
     dtostrf(Value, 13,4, charBuf);
     return charBuf;
}


void saveConfigCallback () {
  Serial.println("Should save config");
  shouldSaveConfig = true;

}
void saveConfig(){
 
    Serial.println("saving config");
    DynamicJsonBuffer jsonBuffer;
    JsonObject& json = jsonBuffer.createObject();
    json["mqtt_server"] = mqtt_server;
   
    File configFile = SPIFFS.open("/config.json", "w");
    if (!configFile) {
      Serial.println("failed to open config file for writing");
    }

    json.printTo(Serial);
    json.printTo(configFile);
    configFile.close(); 
}
void SplitBySpace(String input, String& cmd, String& cmdval){
  for (int i = 0; i < input.length(); i++) {
    if (input.substring(i, i+1) == " ") {
      cmd = input.substring(0, i);
      cmdval= input.substring(i+1);
      break;
    }
  }
}

String GetCurrentTime(bool wait) {
  String datetimestring = "";
  datetimestring = NTP.getTimeDateString();
  if (wait){
    while (datetimestring == "Time not set"){
      datetimestring = NTP.getTimeDateString();
      delay(100);
    }
  }
  return datetimestring;
}


void SetupOTA(){
 
  MDNS.begin(clientName);
  httpUpdater.setup(&httpServer);
  httpServer.begin();
  MDNS.addService("http", "tcp", 1234);
}



void SendRoomba(int code){
  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH);
 roomba_send(code,39,3000,1100,50,3);
 roomba_send(code,38,3000,110,50,3);
 roomba_send(code,39,3000,1000,50,3);
 roomba_send(code,38,3000,1000,50,3);
 pinMode(5, OUTPUT);
  digitalWrite(5, LOW);
 delay(4000);
}

void roomba_send(int code, uint16_t freq,int pulse, int pbreak,int pdelay, int pcount) 
{
  Serial.print("Sending Roomba code ");
  Serial.print(code);
  int length = 8;
  uint16_t raw[length*2];
  unsigned int one_pulse = pulse;
  unsigned int one_break = pbreak;
  unsigned int zero_pulse = one_break;
  unsigned int zero_break = one_pulse;

  int arrayposition = 0;
  // Serial.println("");
  for (int counter = length-1; counter >= 0; --counter) {
    if(code & (1<<counter)) {  
      raw[arrayposition] = one_pulse;
      raw[arrayposition+1] = one_break;
    } 
    else {
      raw[arrayposition] = zero_pulse;
      raw[arrayposition+1] = zero_break;
    }
    arrayposition = arrayposition + 2;
  } 
  for (int i = 0; i < pcount; i++) {
    irsend.sendRaw(raw, ((uint16_t)15), freq);
    delay(pdelay);
  }
  Serial.println("");

  /*
  Serial.print("Raw timings:");
   for (int z=0; z<length*2; z++) {
   Serial.print(" ");
   Serial.print(raw[z]);
   }
   Serial.print("\n\n");
   */
}
void CheckAutomaticRoombaStart(){

  
}
void CheckTemperature(){
  
 
}




