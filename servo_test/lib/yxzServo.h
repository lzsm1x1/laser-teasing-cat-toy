#ifndef yxzServo_h
#define yxzServo_h

#define SERVO_CMMD_SYSTEM_STOP  0
#define SERVO_CMMD_SYSTEM_RUN 1
#define SERVO_DEGREE_HORIZON_MAX 180
#define SERVO_DEGREE_HORIZON_MIN 0
#define SERVO_DEGREE_VERTICAL_MAX 180
#define SERVO_DEGREE_VERTICAL_MIN 0

#define LASER_CMMD_SYSTEM_ON 1
#define LASER_CMMD_SYSTEM_OFF 0

#endif


int pos_horizon = SERVO_DEGREE_HORIZON_MIN;
int pos_vertical = SERVO_DEGREE_VERTICAL_MIN;

const int centerX = 30; // 圆心X对应的舵机角度
const int centerY = 30; // 圆心Y对应的舵机角度
const int radius = 30;  // 圆的半径（角度增量，确保不超过90）
float theta = 0;        // 初始角度
const float thetaIncrement = 0.05; // 角度步长，调整以改变速度
const int delayTime = 15; // 控制循环延迟，影响舵机速度

char servo_cmmd = SERVO_CMMD_SYSTEM_RUN;

void servo_run_horizon();

void servo_run_vertical();

void way1();

void draw_circle();

void servo_stop();