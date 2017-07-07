void setup() {
  Serial.begin(115200);  
  WiFiManager wifiManager;
  setupTemp();
  setupIR();
  
  //wifiManager.resetSettings();
  wifiManager.setSaveConfigCallback(saveConfigCallback);
  //Adding an additional config on the WIFI manager webpage for the bot token
  WiFiManagerParameter custom_bot_id("botid", "Bot Token", bot_token, 50);
  wifiManager.addParameter(&custom_bot_id);

  WiFiManagerParameter custom_mqtt_server("mqtt", "MQTT Server", mqtt_server, 50);
  wifiManager.addParameter(&custom_mqtt_server);
  
  wifiManager.autoConnect(clientName);
  
  strcpy(bot_token, custom_bot_id.getValue());
  strcpy(mqtt_server, custom_mqtt_server.getValue());
  LoadSetup();
 
  Serial.print("botToken: ");
  Serial.println(bot_token);
  
  bot = new UniversalTelegramBot(bot_token, client);
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);

}
