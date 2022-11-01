#include <WiFiClient.h>
#include <ESP8266WebServer.h>
//#include <uri/UriBraces.h>
#include "webpg.h"
#include <LittleFS.h>

ESP8266WebServer wserver(80);
File uploadFile;
File oldFile;
FS* fileSystem = &LittleFS;
bool oldmusic;

void replyServerError(String msg) {
  //Serial.println(msg);
  wserver.send(500, "text/plain", msg + "\r\n");
}

void setupWeb(void) {
  Serial.begin(115200);
  Serial.println("");
  wserver.on(F("/"), []() {
    wserver.send(200, "text/html", INDEX_HTML);
  });

 // wserver.on(UriBraces("/cmd/{}"), []() {
 wserver.onNotFound([]() {
 String ur=wserver.uri();
 Serial.println(ur);
  if(!ur.startsWith("/cmd/")){return;}
    String cmd = ur.substring(5);
Serial.println(cmd);
    if (!cmd.compareTo( "LED1")) {
      led1 = !led1;
      wserver.send(204, "", "");
    } else if (!cmd.compareTo( "LED2")) {
      led2 = !led2;
      wserver.send(204, "", "");
    } else if (!cmd.compareTo( "TRAIN")) {
      train = !train;
      wserver.send(204, "", "");
    } else if (!cmd.compareTo( "MUSIC")) {
      music = !music;
      wserver.send(204, "", "");
    } else if (!cmd.compareTo( "VP")) {
      vol = vol + (vol <= 5 ? 1 : 0);
      wserver.send(204, "", "");
    } else if (!cmd.compareTo( "VM")) {
      vol = vol - (vol >= 0 ? 1 : 0);
      wserver.send(204, "", "");
    } else if (!cmd.compareTo( "music.mp3")) {
      oldFile = fileSystem->open("/pno-cs.mp3", "r");
 //     wserver.send(200,mime::getContentType("/pno-cs.mp3",)
      if (wserver.streamFile(oldFile, mime::getContentType("/pno-cs.mp3")) != oldFile.size()) {
        //Serial.println("Sent less data than expected!");
      }
      oldFile.close();
      return;
    } else if (!cmd.compareTo( "RST")) {
      
      oldmusic = music;
      music = false;
      uploadFile = fileSystem->open("/pno-cs.mp3", "w");
      oldFile = fileSystem->open("/rst.mp3", "r");
      while (oldFile.available())
      {
        uploadFile.write(oldFile.read());
      }
      uploadFile.close();
      oldFile.close();
      delay(500);
      music = oldmusic;
     wserver.send(200, "text/plain", "Music reseted!");
    }
    //exe cmd
  });
 /* wserver.onNotFound([]() {
    wserver.send(204, "", "");
  });*/

  wserver.on("/upload", HTTP_POST, []() {
    oldmusic = music;
    music = false;
    wserver.sendHeader("Connection", "close");
    wserver.send(200, "text/plain", "Music updated!");
  }, []() {
    HTTPUpload& upload = wserver.upload();
    if (upload.status == UPLOAD_FILE_START) {
      String filename = "/pno-cs.mp3";
      //Serial.println(String("handleFileUpload Name: ") + filename);
      uploadFile = fileSystem->open(filename, "w");
      if (!uploadFile) {
        return replyServerError(F("CREATE FAILED"));
      }
      //Serial.println(String("Upload: START, filename: ") + filename);
    } else if (upload.status == UPLOAD_FILE_WRITE) {
      if (uploadFile) {
        size_t bytesWritten = uploadFile.write(upload.buf, upload.currentSize);
        if (bytesWritten != upload.currentSize) {
          return replyServerError(F("WRITE FAILED"));
        }
      }
      //Serial.println(String("Upload: WRITE, Bytes: ") + upload.currentSize);
    } else if (upload.status == UPLOAD_FILE_END) {
      if (uploadFile) {
        uploadFile.close();
        delay(500);
        music = oldmusic;
      }
      //Serial.println(String("Upload: END, Size: ") + upload.totalSize);
    }
  });








  wserver.begin();
  //Serial.println("HTTP wserver started");
}

void loopWeb(void) {
  wserver.handleClient();
  delay(1);
}
