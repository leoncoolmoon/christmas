#include <Servo.h>

#define SERVO_PIN         2//(gpio 2,pin D4)
#define REFRESH_PERIOD_MS 10
//#define NOW               1

Servo myservo;
int uplmt = 170;
int btlmt = 10;
int servo_position = uplmt;
bool clockwise = true;


void setupTrain(){
   myservo.attach(SERVO_PIN);
 }

void loopTrain() {
  if (train ) {
    servo_position = servo_position + (clockwise ? (-1) : (+1));
    clockwise = servo_position >= uplmt ? true : servo_position <= btlmt ? false : clockwise;
    myservo.write(servo_position);              // tell servo to go to position in variable 'pos'
    delay(REFRESH_PERIOD_MS);        // waits 20ms for refresh period
    
  }}
