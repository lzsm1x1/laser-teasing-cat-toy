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

  
                2.Add #define name rule, update the name of definition.

  #define name rule : [item]_[type]_[category]_[Detial]
              instance: SERVO_CMMD_SYSTEM_STOP
                        LASER_CMMD_SWITCH_ON

  function name rule : []

  variable name rule : []
  */

#include <Servo.h>

#define SERVO_CMMD_SYSTEM_STOP  0
#define SERVO_CMMD_SYSTEM_RUN 1
#define SERVO_DEGREE_HORIZON_MAX 180
#define SERVO_DEGREE_HORIZON_MIN 0
#define SERVO_DEGREE_VERTICAL_MAX 180
#define SERVO_DEGREE_VERTICAL_MIN 0

int pos_horizon = SERVO_DEGREE_HORIZON_MIN;
int pos_vertical = SERVO_DEGREE_VERTICAL_MIN;

char servo_cmmd = SERVO_CMMD_SYSTEM_RUN;
Servo servo_horizon;                            // create servo object to control a servo
Servo servo_vertical;
                                          // twelve servo objects can be created on most boards
void setup() {
  // servo_horizon.attach(9, 500, 2500);
  servo_horizon.attach(2);                      // attaches the servo on GIO2(D4) to the servo object
  servo_vertical.attach(0);                     // attaches the servo on GIO0(D3) to the servo object
  Serial.begin(9600);
  Serial.println("ok");


}
void loop() {
  // servo_cmmd = Serial.read();
  // Serial.println(servo_cmmd);
  if(servo_cmmd == MOTOR_CMMD_SYSTEM_STOP)
  {
    servo_stop();
  }
  else if(servo_cmmd == MOTOR_CMMD_SYSTEM_RUN)
  {
    way1();
    // servo_run_horizon();
    // servo_run_vertical();
  }else{
    delay(20);
    //Do no thing
  }

}

void servo_run_horizon()
{
  Serial.println("servo_run_horizon");
  for (pos_horizon = SERVO_DEGREE_HORIZON_MIN; pos_horizon <= SERVO_DEGREE_HORIZON_MAX; pos_horizon += 1) {   // goes from 0 degrees to 180 degrees
    servo_horizon.write(pos_horizon);                   // tell servo to go to pos_horizonition in variable 'pos_horizon'
    //Serial.println(pos_horizon);                  // waits 15ms for the servo to reach the pos_horizonition
    delay(15);
  }
  for (pos_horizon = SERVO_DEGREE_HORIZON_MAX; pos_horizon >= SERVO_DEGREE_HORIZON_MIN; pos_horizon -= 1) {   // goes from 180 degrees to 0 degrees
    servo_horizon.write(pos_horizon);
    //Serial.println(pos_horizon);                  // tell servo to go to pos_horizonition in variable 'pos_horizon'
    delay(15);                            // waits 15ms for the servo to reach the pos_horizonition
  }
}

void servo_run_vertical()
{
  Serial.println("servo_run_horizon");
  for (pos_vertical = SERVO_DEGREE_HORIZON_MIN; pos_vertical <= SERVO_DEGREE_VERTICAL_MAX; pos_vertical += 1) {   // goes from 0 degrees to 180 degrees
    servo_vertical.write(pos_vertical);                   // tell servo to go to pos_horizonition in variable 'pos_horizon'
    //Serial.println(pos_vertical);                  // waits 15ms for the servo to reach the pos_horizonition
    delay(15);
  }
  for (pos_vertical = SERVO_DEGREE_VERTICAL_MAX; pos_vertical >= SERVO_DEGREE_HORIZON_MIN; pos_vertical -= 1) {   // goes from 180 degrees to 0 degrees
    servo_vertical.write(pos_vertical);
    //Serial.println(pos_vertical);                  // tell servo to go to pos_horizonition in variable 'pos_horizon'
    delay(15);                            // waits 15ms for the servo to reach the pos_horizonition
  }
}

void way1()
{
  int toward = 1; //define the diraction of servo
  //The horizon diraction of servo is moved as normal(1 degree per cycle), vertical servo is performs reciprocating motion at an angle of 0-30 degrees(2 degree per cycle)
  for (pos_horizon = SERVO_DEGREE_HORIZON_MIN; pos_horizon <= SERVO_DEGREE_HORIZON_MAX; pos_horizon += 1) {   
    if(toward == 1)
    {
          if(pos_vertical <= 30 && pos_vertical >= 0){
            pos_vertical += 2;
          }else
          {
            toward = 0;
          }
    }else
    {
          if(pos_vertical != 0){
            pos_vertical -= 2;
          }else
          {
            toward = 1;
          }
    }

    servo_vertical.write(pos_vertical);
    servo_horizon.write(pos_horizon);                   // tell servo to go to pos_horizonition in variable 'pos_horizon'
    // Serial.println("pos_horizon"); 
    // Serial.println(pos_horizon);                  
    // Serial.println("pos_vertical");
    // Serial.println(pos_vertical);
    delay(15);
  }
}

void servo_stop()
{
  //Serial.println("MOTOR_CMMD_SYSTEM_STOP");
    servo_horizon.write(SERVO_DEGREE_HORIZON_MIN);                   // tell servo to go to degree '0'
    servo_vertical.write(SERVO_DEGREE_VERTICAL_MIN);
}