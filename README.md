# laser-teasing-cat-toy

预期的结果：二位云台控制激光模块逗猫

需求： 舵机*2 激光模块*1 电源适配器*1 开发板（NodeMCU）*1 线束规划 模型优化 随机算法保证激光位置的随机

v0.1 This is a test project, to test the NodeMCU , motor and serial is ok.
v0.2 use 2 motor to control 1 laser module, but these 2 motor are controled by the same pin GIO2(D4)
v0.3 Add a function witch is called "way1", this simple algorithm allows two servos to control the lazer move like sawtooth wave. 

![初版模型](image.png)
使用了该模型：
https://makerworld.com.cn/models/428396