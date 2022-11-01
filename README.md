# christmas
my DIY Christmas Village and Train 

https://www.thingiverse.com/thing:5599288
https://youtube.com/shorts/ej0nH_mT4Pg?feature=share

material list:

1. 1x Wemos D1 mini (ESP8266)
2. 1x 9g servo(180/360default you can change it in the code)
3. 2x  line of LEDs in parallel
4. 1x speaker
5. 1x s8050 or other npn
6. 1x 100 uF capacitor
7. 1x 100 ohm resistor
there are more GPIO for upgrade

wiring:
 1.sound amplifier and speaker
   NPN: s8050
   C1: 100 uF 
   R1: 100 ohm
   small speaker
   
     Rx ---- +C1- -----(NPNb)-\ 
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
 
 
 
 
