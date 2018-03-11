#define KITKAT (1000UL * 60 * 1)
unsigned long rolltime = millis() + KITKAT;


void loop() {
  if((long)(millis() - rolltime) >= 0) {
     PublishMessage(GetMeasurement());
     rolltime += KITKAT;
 }
  pubsubclient.loop();
}

void PublishMessage(char* message)
{
  PubSubConnect();
  Serial.println(message);
  pubsubclient.publish(OUT_FEED,message);
}

char* GetMeasurement()
{

  StaticJsonBuffer<500> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["dt"] = GetCurrentTime(true);
  root["SrvT"] = String(bmp.readTemperature());
  root["SrvP"] = String(bmp.readPressure());
  root["OutT"] = String(ReadDS1820());
  
  char buffer[256];
  root.printTo(buffer, sizeof(buffer));
  return buffer;
}
float ReadDS1820(){
DS1820.requestTemperatures();
    float t = DS1820.getTempCByIndex(0);
    return t;
}

