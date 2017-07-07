void setup() {
  Serial.begin(115200);  
  WiFiManager wifiManager;
  
  setupNTP();
  setupIR();
  setupTemp();
  
  //wifiManager.resetSettings();
  LoadSetup();

  wifiManager.setSaveConfigCallback(saveConfigCallback);
  //Adding an additional config on the WIFI manager webpage for the bot token
  //WiFiManagerParameter custom_bot_id("botid", "Bot Token", bot_token, 50);
  //wifiManager.addParameter(&custom_bot_id);
  WiFiManagerParameter custom_mqtt_server("mqtt", "MQTT Server", mqtt_server, 50);
  wifiManager.addParameter(&custom_mqtt_server);
  wifiManager.autoConnect("SetupHotSpot");
  wifiManager.setSaveConfigCallback(saveConfigCallback);
  
  //strcpy(bot_token, custom_bot_id.getValue());
  strcpy(mqtt_server, custom_mqtt_server.getValue());
   if (shouldSaveConfig) {
      saveConfig();
   }  
  
  Serial.print("MQTT Server: ");
  Serial.println(mqtt_server);
  SetupPubSub();
  PubSubConnect();

}
void PubSubConnect() {
  while (!pubsubclient.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (pubsubclient.connect(clientName,WILL_FEED,1,false, clientName)) {
      
      pubsubclient.subscribe("/office/flurboxin");
      Serial.println("connected");
    } 
    else 
    {
      Serial.print("failed, rc=");
      Serial.print(pubsubclient.state());
      delay(1000);
    }
  }
}

void setupTemp() {
  Wire.begin(12,13);
  bmp.begin();  
}

void SetupPubSub(){
  pubsubclient.setServer(mqtt_server, 1883);
  pubsubclient.setCallback(pubsubCallback);
}


void pubsubCallback(char* topic, byte* payload, unsigned int length) {
  String json = String((char *)payload);
  Serial.print("Raw message: ");
  Serial.println(json);
  StaticJsonBuffer<400> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(json);
  //const char* messagetype  = root["type"];Serial.print("MessageType: ");  Serial.println(messagetype);
  //const char* content   = root["content"];
  const char* action = root["action"];
  const char* cmdval = root["cmdval"];
  
  Serial.print("action: ");Serial.println(action);
  Serial.print("cmdval: "); Serial.println(cmdval);

  if (action == "gertrud"){
      SendRoomba(136);
  }
  if(action == "roombacode"){
    SendRoomba(atoi(cmdval));
  }
  
}


