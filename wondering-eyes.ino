/* Sweep
  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 28 May 2015
  by Michael C. Miller
  modified 8 Nov 2013
  by Scott Fitzgerald

  http://arduino.cc/en/Tutorial/Sweep
*/

int spd = 30;
#include <Servo.h>


Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int pos = 0;
int svMax = 90;
int svMin = 55;
int newPos = 55;
int cpos = 55;  //current pos
void setup() {
   Serial.begin(9600);
  myservo.attach(12);  // attaches the servo on GIO2 to the servo object
}

void loop() {
    
    newPos = random(svMin,svMax);
    spd = random(15,50);
    delay(random(600,1200));
    Serial.println(newPos);
    
    if (newPos < cpos){
      for (pos = cpos; pos > newPos; pos -= 2){
        // delay(3);
        //Serial.write(newPos);
         delay(3);
         myservo.write(pos);
         
          delay(spd);
        }
      cpos = newPos;
    }

    if (newPos > cpos){
      for (pos = cpos; pos < newPos; pos += 2){
        delay(3);
       // Serial.write(newPos);
       //  delay(3);
         myservo.write(pos);
          delay(spd);
        }
      cpos = newPos;
    }

}
