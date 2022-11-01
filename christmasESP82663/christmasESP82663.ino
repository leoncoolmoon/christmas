//12 14 FOR LED 15 FOR SERVO RX FOR MUSIC ?////4 FOR VOLUME
#define MUSIC_PLAY
#define TRAIN_RUN
#define LED_LIGHT
#define WIFI_CONN
#ifdef WIFI_CONN
#define WEB_UI
#define OTA_UPDT
#endif

extern bool led1 = true;
extern bool led2 = true;
extern bool train = true;
extern bool music = true;
extern bool musicDone = true;
extern int vol = 3;

#ifdef MUSIC_PLAY
#include "music.h"
#else
#include <LittleFS.h>
#endif
#ifdef WIFI_CONN
#include "wifisetup.h"
#ifdef OTA_UPDT
#include "OTA.h"
#endif
#ifdef WEB_UI
#include "web_app.h"
#endif
#else
#include <ESP8266WiFi.h>
#endif
#ifdef TRAIN_RUN
#include "servo360.h"
//#include "servo180.h"
#endif
#ifdef LED_LIGHT
#include "led_l.h"
#endif



void setup()
{

  //Serial.begin(115200);
#ifdef TRAIN_RUN
  setupTrain();
#endif
  //LittleFS.format();
  LittleFS.begin();
  Dir dir = LittleFS.openDir ("");
  while (dir.next ()) {
    //Serial.println (dir.fileName ());
  }


#ifdef LED_LIGHT
  // Serial.println ("setupLed");
  setupLed();
#endif
#ifdef MUSIC_PLAY
  // Serial.println ("playMp3");
  playMp3();
#endif
#ifdef WIFI_CONN
  // Serial.println ("setupWiFi");
  setupWiFi();
#ifdef OTA_UPDT
  // Serial.println ("setupOTA");
  setupOTA();
#endif
#ifdef WEB_UI
  //  Serial.println ("setupWeb");
  setupWeb();
#endif
#else
  // Serial.println ("WIFI_OFF");
  WiFi.mode(WIFI_OFF);
#endif
}


void loop()
{
#ifdef MUSIC_PLAY
  // Serial.println ("loopMusic");
  loopMusic();
#endif
#ifdef WIFI_CONN
#ifdef OTA_UPDT
  //  Serial.println ("loopOTA");
  loopOTA();
#endif
#ifdef WEB_UI
  // Serial.println ("loopWeb");
  loopWeb();
#endif
#endif
#ifdef TRAIN_RUN
    //Serial.print ("loopTrain ");
   //Serial.println (train);
  loopTrain();
#endif
#ifdef LED_LIGHT
  //  Serial.println ("loopLed");
  loopLed();
#endif
 
}
