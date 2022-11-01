#include <Arduino.h>

int ledPin0 = 12 ;//pin D6
int ledPin1 = 14 ;//pin D5
float led_brightness = 5.0;
float changeRate = 0.1;
boolean fading = false;
float k = 0.0;
float j = 0.0;

void setupLed(){
  pinMode(ledPin0, OUTPUT);
  pinMode(ledPin1, OUTPUT);  
  }

void loopLed() {
  led_brightness = led_brightness + (fading ? (-1.0) : (+1.0))*changeRate;
  fading = led_brightness >= 255.0 ? true : led_brightness <= 0.0 ? false : fading;
  k = led_brightness > 128.0 ? led_brightness - 128.0 : 0.0; //128-255
  j = (176.0 > led_brightness) && (led_brightness > 48.0) ? led_brightness > 112.0 ? 176.0 - led_brightness : led_brightness - 48.0 : 0.0; //64-192
  analogWrite(ledPin0, round(led1 ? k : 0.0));
  analogWrite(ledPin1, round(led2 ? j * 2.0 : 0.0));
}
