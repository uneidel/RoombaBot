void handleNewMessages(int numNewMessages) {
  Serial.println("handleNewMessages");
  Serial.println(String(numNewMessages));
  for(int i=0; i<numNewMessages; i++) {
    String chat_id = String(bot->messages[i].chat_id);
    String fullmsg = bot->messages[i].text;
    fullmsg.toLowerCase();
    Serial.print("Text : ");Serial.println(fullmsg);
    String cmd, cmdval;
    SplitBySpace(fullmsg, cmd, cmdval);
    Serial.print("Command: ");Serial.println(cmd);
    Serial.print("CmdVal: ");Serial.println(cmdval);
    if (cmd == "/setalerttemp") {

      String message = "New AlarmTime Set to ";
      message = message + cmdval;
      bot->sendMessage(chat_id, message, "");
    }
    if (cmd == "/setroombatime") {
     
      bot->sendMessage(chat_id, "Led is OFF", "");
    }
    if (cmd == "/status") {
      
    }
    if (cmd == "/temperature") {
        String message = "Current Temperature: ";
        message = message + String(bmp.readTemperature());
        bot->sendMessage(chat_id, message, "");
    }
    if (cmd == "/gertrud") {
       SendRomba(136);
       String message = "Roomba started.";
       bot->sendMessage(chat_id, message, "");
    }
    if (cmd=="/ip"){
       String message = "current ip: ";
       message += String(WiFi.localIP());
       bot->sendMessage(chat_id, message, "");
    }
    if (cmd=="/ota"){
       SetupOTA();
       
    }
     if (text == "/options") {
      String keyboardJson = "[[\"/ledon\", \"/ledoff\"],[\"/status\"]]";
      bot.sendMessageWithReplyKeyboard(chat_id, "Choose from one of the following options", "", keyboardJson, true);
    }
    if (cmd == "/start") {
      String welcome = "Welcome from FlurBot! \n";
      welcome = welcome + "/setalerttemp [value]: Set alert temperature ON\n";
      welcome = welcome + "/setroombatime [value] : Set roomba automatic start  OFF\n";
      welcome = welcome + "/status : Returns current status\n";
      welcome = welcome + "/gertrud: Start Roomba\n";
      welcome = welcome + "/temperature: get Temperature\n";
      welcome = welcome + "/ip: get ip\n";
      welcome = welcome + "/ota: set ota mode\n";
      bot->sendMessage(chat_id, welcome, "Markdown");
    }
    
  }
}
