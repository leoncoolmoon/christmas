#include <ESP8266WiFi.h>
#define STASSID "christmas"
#define STAPSK  "1234567890"

const char *ssid = STASSID;
const char *password = STAPSK;
void setupWiFi(){
  delay(1000);
   Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
    WiFi.softAP(ssid, password);
      delay(1000);
    }
