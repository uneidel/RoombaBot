
/*
 IR Remote Control
 129 Left 
 130 Forward 
 131 Right 
 132 Spot 
 133 Max 
 134 Small 
 135 Medium 
 136 Large / Clean 
 137 Stop 
 138 Power 
 139 Arc Left 
 140 Arc Right 
 141 Stop  
 
 Scheduling Remote  
 142 Download 
 143 Seek Dock 
 
 Roomba Discovery Driveon Charger 
 240 Reserved 
 248 Red Buoy 
 244 Green Buoy 
 242 Force Field 
 252 Red Buoy and Green Buoy 
 250 Red Buoy and Force Field 
 246 Green Buoy and Force Field 
 254 Red Buoy, Green Buoy and Force 
 
 Roomba 500 Drive-on Charger
 160 Reserved 
 161 Force Field 
 164 Green Buoy 
 165 Green Buoy and Force Field 
 168 Red Buoy 
 169 Red Buoy and Force Field 
 172 Red Buoy and Green Buoy 
 173 Red Buoy, Green Buoy and Force Field
 
 Roomba 500 Virtual Wall
 162 Virtual Wall 
 
 Roomba 500 Virtual Wall Lighthouse ###### (FIXME: not yet supported here)
 0LLLL0BB 
 LLLL = Virtual Wall Lighthouse ID
 (assigned automatically by Roomba 
 560 and 570 robots) 
 1-10: Valid ID 
 11: Unbound 
 12-15: Reserved 
 BB = Which Beam
 00 = Fence 
 01 = Force Field 
 10 = Green Buoy 
 11 = Red Buoy
 
 */



 /*

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



*/
