#include <Servo.h>

#define SERVO_PIN         2//(gpio 2,pin D4)
#define REFRESH_PERIOD_MS 20
//#define NOW               1

Servo myservo;
int stop_pos = 90;
int clockwise_pos = 98;
int anticlockwise_pos = 75;
int servo_position = stop_pos;
bool clockwise = true;
static bool runtrain = false;

void setupTrain(){
   myservo.attach(SERVO_PIN);
     //Serial.begin(115200);

 }

void loopTrain() {
  if (train != runtrain){
  if (train) {
    //Serial.println(clockwise_pos);
    myservo.write(clockwise_pos);              // tell servo to go to position in variable 'pos'
  }else{
    //Serial.println(stop_pos);
    myservo.write(stop_pos); 
    }
    runtrain =train ;
  }
  }
