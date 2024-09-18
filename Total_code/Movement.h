#ifndef MOVEMENT_FUNCTIONS_H
#define MOVEMENT_FUNCTIONS_H

//#include <Wire.h>
//#include <Adafruit_MPU6050.h>
//#include <Adafruit_Sensor.h>
#include <math.h>

//motors macros
#define MOTOR_RIGHT_PIN1 5
#define MOTOR_RIGHT_PIN2 18
#define MOTOR_LEFT_PIN1 4
#define MOTOR_LEFT_PIN2 0

void moveForward(int distance);
void turnLeft();
void turnRight();


#endif
