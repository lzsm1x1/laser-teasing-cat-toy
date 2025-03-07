

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