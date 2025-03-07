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

  2025/3/3 v0.1 This is a test project, to test the NodeMCU , motor and serial is ok.
  2025/3/4 v0.2 use 2 motor to control 1 laser module, but these 2 motor are controled by the same pin GIO2(D4)
  2025/3/6 v0.3 1.Add a function witch is called "way1", this simple algorithm allows two servos to control the laser move like sawtooth wave. 
                2.Add #define name rule, update the name of definition.
  2025/3/7 v0.4 1.Add yxzServo.h to declare the variable and macro of my servo-project.alignas
                2.Add a function witch is called "draw_circle", this simple algorithm allows two servos to control the laser move like a circle.
                Note: I try to find a way to declare the function in cpp file, wo that I don't have to declare in main file.
                
  #define name rule : [item]_[type]_[category]_[Detial]
              instance: SERVO_CMMD_SYSTEM_STOP
                        LASER_CMMD_SWITCH_ON

  function name rule : []

  variable name rule : []
  */

#include <Servo.h>
#include "./lib/yxzServo.h"



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
  if(servo_cmmd == SERVO_CMMD_SYSTEM_STOP)
  {
    servo_stop();
  }
  else if(servo_cmmd == SERVO_CMMD_SYSTEM_RUN)
  {
    if(theta >= 2*PI)
    {
      way1();
      theta = 0;
    }
    draw_circle();
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
  for (pos_horizon = SERVO_DEGREE_HORIZON_MIN; pos_horizon <= 60; pos_horizon += 1) {   
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

void draw_circle()
{
  // 计算当前点的坐标
  int posX = centerX + radius * cos(theta);
  int posY = centerY + radius * sin(theta);
  
  // 约束角度在0-180之间
  posX = constrain(posX, 0, 180);
  posY = constrain(posY, 0, 180);
  
  // 设置舵机角度
  servo_horizon.write(posX);
  servo_vertical.write(posY);
  
  // 更新角度θ，保持在0-2π范围内
  theta += thetaIncrement;
  // if (theta >= 2 * PI) {
  //   theta -= 2 * PI;
  // }
  
  delay(delayTime); // 控制运动速度
}

void servo_stop()
{
  //Serial.println("MOTOR_CMMD_SYSTEM_STOP");
    servo_horizon.write(SERVO_DEGREE_HORIZON_MIN);                   // tell servo to go to degree '0'
    servo_vertical.write(SERVO_DEGREE_VERTICAL_MIN);
}