void loop() {
 
  CheckTemperature();
  CheckAutomaticRoombaStart();
  
  if (millis() > Bot_lasttime + Bot_mtbs)  {
    int numNewMessages = bot->getUpdates(bot->last_message_received + 1);
    while(numNewMessages) {
      Serial.println("got response");
      handleNewMessages(numNewMessages);
      numNewMessages = bot->getUpdates(bot->last_message_received + 1);
    }
    Bot_lasttime = millis();
  }
}


  

void CheckAutomaticRoombaStart(){

  
}
void CheckTemperature(){
  
  if (curloop > maxcurloop){
   curloop = 0;
   // Validate Temperature
   float curtemp = bmp.readTemperature();
   if (curtemp > maxcurtemp){
     //send message
     String chat_id = String(bot->messages[0].chat_id);
     bot->sendMessage(chat_id, "Temperature too high Current Temperature:", "");
   }
  }

}
