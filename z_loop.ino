#define FIVEMIN (1000UL * 60 * 5)
unsigned long rolltime = millis() + FIVEMIN;


void loop() {
 
  CheckTemperature();
  CheckAutomaticRoombaStart();

   
 
 if((long)(millis() - rolltime) >= 0) {

   //  Do your five minute roll stuff here
PublishMessage(GetCurrentTempMessage());
   rolltime += FIVEMIN;

 }
  pubsubclient.loop();

}

void PublishMessage(char* message)
{
  PubSubConnect();
  pubsubclient.publish("/office/flurboxout",message);
}

char* GetCurrentTempMessage()
{

  StaticJsonBuffer<400> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["DateTime"] = GetCurrentTime(true);
  root["Temperature"] = String(bmp.readTemperature());
  char buffer[256];
  root.printTo(buffer, sizeof(buffer));
  return buffer;
}

char* GetJsonMessage(char* message)
{

  StaticJsonBuffer<400> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["DateTime"] = GetCurrentTime(true);
  root["message"] = message;
  char buffer[256];
  root.printTo(buffer, sizeof(buffer));
  return buffer;
}
