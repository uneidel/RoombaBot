
#include <FS.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <EEPROM.h>
#include <DNSServer.h>            //Local DNS Server used for redirecting all rs to the configuration portal
#include <ESP8266WebServer.h>     //Local WebServer used to serve the configuration portal
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager WiFi Configuration Magic
#define BOT_TOKEN_LENGTH 46
#include <ESP8266mDNS.h>
#include <ESP8266HTTPUpdateServer.h>
#include <NtpClientLib.h>

#define clientName "flurbox"
#define WILL_FEED "/devices"
#define OUT_FEED "/office/boxout"
#define IN_FEED "/office/boxin"

const int maxcurloop =100;
const int maxcurtemp = 50;

//flag for saving data
bool shouldSaveConfig = false;
char bot_token[BOT_TOKEN_LENGTH] = "";

char mqtt_server[40];
WiFiClientSecure client;
UniversalTelegramBot *bot;

int Bot_mtbs = 1000; //mean time between scan messages
long Bot_lasttime;   //last time messages' scan has been done
bool Start = false;

ESP8266WebServer httpServer(1234);
ESP8266HTTPUpdateServer httpUpdater;
int curloop = 0;

