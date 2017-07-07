
#include <FS.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <EEPROM.h>
#include <DNSServer.h>            
#include <ESP8266WebServer.h>    
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager WiFi Configuration Magic
#include <ESP8266mDNS.h>
#include <ESP8266HTTPUpdateServer.h>
#include <NtpClientLib.h>
#include <IRsend.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <ArduinoJson.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include <PubSubClient.h>


#define clientName "flurbox"
#define WILL_FEED "/devices"
#define OUT_FEED "/office/flurboxout"
#define IN_FEED "/office/flurboxin"
#define BOT_TOKEN_LENGTH 46

const int maxcurtemp = 50;
bool shouldSaveConfig = false;
char bot_token[BOT_TOKEN_LENGTH] = "";

char mqtt_server[40];
WiFiClient espClient;

ESP8266WebServer httpServer(1234);
ESP8266HTTPUpdateServer httpUpdater;
int curloop = 0;
PubSubClient pubsubclient(espClient);
IRsend irsend(5); 
Adafruit_BMP085 bmp;




  


