#include <Arduino.h>
#include <AudioFileSourceLittleFS.h>
#include "AudioFileSourceID3.h"
#include "AudioGeneratorMP3.h"
#include "AudioOutputI2SNoDAC.h"
// To run, set your ESP8266 build to 160MHz, and include a SPIFFS of 512KB or greater.
// Use the "Tools->ESP8266/ESP32 Sketch Data Upload" menu to write the MP3 to SPIFFS
// Then upload the sketch normally.
/* NPN: s8050
 * Rx--- +C1- ---(NPNb)-\ 
 * G-------------(NPNe)  R
 * 5V--- +SP- ---(NPNc)-/
 */
// pno_cs from https://ccrma.stanford.edu/~jos/pasp/Sound_Examples.html

AudioGeneratorMP3 *mp3;
AudioFileSourceLittleFS *file;
AudioOutputI2SNoDAC *out;
AudioFileSourceID3 *id3;
static int volume = 4;
// Called when a metadata event occurs (i.e. an ID3 tag, an ICY block, etc.

void MDCallback(void *cbData, const char *type, bool isUnicode, const char *string)
{
  (void)cbData;
  //Serial.printf("ID3 callback for: %s = '", type);

  if (isUnicode) {
    string += 2;
  }

  while (*string) {
    char a = *(string++);
    if (isUnicode) {
      string++;
    }
    //Serial.printf("%c", a);
  }
  //Serial.printf("'\n");
  //Serial.flush();
}

void playMp3() {
  //Serial.begin(115200);
  //Serial.printf("Sample MP3 playback begins...\n");
  file = new AudioFileSourceLittleFS("/pno-cs.mp3");
  id3 = new AudioFileSourceID3(file);
  id3->RegisterMetadataCB(MDCallback, (void*)"ID3TAG");
  out = new AudioOutputI2SNoDAC();
  mp3 = new AudioGeneratorMP3();
  mp3->begin(id3, out);
  //mp3->loop();
  audioLogger = &Serial;
  if (vol != volume) {
          //Serial.print("vol =");
          //Serial.println(vol);
          out->SetGain(((float)vol) * 0.3);
          volume = vol;
        }
}

void loopMusic() {
  //Serial.print("music=");
  //Serial.println(music);
  if (mp3->isRunning()) {
    if (!music) {
      mp3->stop();
    } else {
      if (!mp3->loop()) {
        mp3->stop();
        musicDone = true;
      } else {
        if (vol != volume) {
          //Serial.print("vol =");
          //Serial.println(vol);
          out->SetGain(((float)vol) * 0.3);
          volume = vol;
        }
      }
    }

  } else {
    if (music) {
      //musicDone = false;
      playMp3();
    }
  }
}
