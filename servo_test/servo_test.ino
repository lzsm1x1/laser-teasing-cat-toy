/* 
  Based on Sweep
  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 28 May 2015
  by Michael C. Miller
  modified 8 Nov 2013
  by Scott Fitzgerald

  http://arduino.cc/en/Tutorial/Sweep

  I hope that I can make a laser teasing cat toy.

  v0.1 This is a test project, to test the NodeMCU , motor and serial is ok. 
*/

#include <Servo.h>

int pos = 0;
Servo myservo;                            // create servo object to control a servo
                                          // twelve servo objects can be created on most boards
void setup() {
  // myservo.attach(9, 500, 2500);
  myservo.attach(2);                      // attaches the servo on GIO2(D4) to the servo object
  Serial.begin(9600);
  Serial.println("ok");
}
void loop() {
  Serial.println("in loop");
  for (pos = 0; pos <= 180; pos += 1) {   // goes from 0 degrees to 180 degrees
    myservo.write(pos);                   // tell servo to go to position in variable 'pos'
    Serial.println(pos);                  // waits 15ms for the servo to reach the position
    delay(15);
  }
  for (pos = 180; pos >= 0; pos -= 1) {   // goes from 180 degrees to 0 degrees
    myservo.write(pos);
    Serial.println(pos);                  // tell servo to go to position in variable 'pos'
    delay(15);                            // waits 15ms for the servo to reach the position
  }
}