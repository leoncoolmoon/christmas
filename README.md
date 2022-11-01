# christmas
my DIY Christmas Village and Train music box</br>
Support webpage control </br>
Support OTA </br>

https://www.thingiverse.com/thing:5599288</br>
https://youtube.com/shorts/ej0nH_mT4Pg?feature=share

## material list:

1. 1x Wemos D1 mini (ESP8266)
2. 1x 9g servo(180/360default you can change it in the code)
3. 2x  line of LEDs in parallel
4. 1x speaker
5. 1x s8050 or other npn
6. 1x 100 uF capacitor
7. 1x 100 ohm resistor
there are more GPIO for upgrade

## wiring:

 1.sound amplifier and speaker</br>
   1.1 NPN: s8050</br>
   1.2 C1: 100 uF </br>
   1.3 R1: 100 ohm</br>
   1.4 small speaker</br>
   
     Rx ------- +C1- --(NPNb)-\ 
     G  ---------------(NPNe) R1
     5V/3.3V -- +SP- --(NPNc)-/
 
 2.led
 
     D5 ---- +LEDs1- ----G
     D6 ---- +LEDs2- ----G
 
 3.servo
 
     D4 ---- 9g servo(360 / 180)- ----G
                   +
                   |
                   5V
 
 
 
 
