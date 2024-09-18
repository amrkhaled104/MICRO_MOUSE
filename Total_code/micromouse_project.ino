
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <math.h>
#include "algorithm.h"
#include "encoder.h"
#include "gyroscope.h"
#include "movement.h"
#include "walls.h"
extern float anglez;
extern float lasttime;
/*
//////////macros/////////////////////////

/////ir macros//////////
#define FRONT_SENSOR_PIN 25
#define LEFT_SENSOR_PIN 27
#define RIGHT_SENSOR_PIN 34
//motors macros
#define MOTOR_RIGHT_PIN1 5
#define MOTOR_RIGHT_PIN2 8
#define MOTOR_LEFT_PIN1 4
#define MOTOR_LEFT_PIN2 0

////////// algo macros
#define MAZE_SIZE 16
#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3
const int encoderPinA = 2; 

////////algor var
short direction = NORTH;
short robot_x = 15;
short robot_y = 0;

int maze[MAZE_SIZE][MAZE_SIZE]; 
bool walls[MAZE_SIZE][MAZE_SIZE] = {false};

/////////////////encoder var///////////////////
const int PPR = 20; // Pulses per revolution
const float wheelDiameter = 10.0; // Diameter of the wheel in cm
const float wheelCircumference = 3.14159 * wheelDiameter; // Circumference of the wheel

// Variables to store pulse counts
volatile long pulseCount = 0;

// Interrupt service routine for encoder
void ISR_encoder() {
  pulseCount++;
}
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void pinmodes()
{ 
  
/////////////irs
  pinMode(FRONT_SENSOR_PIN, INPUT);
  pinMode(RIGHT_SENSOR_PIN, INPUT);
  pinMode(LEFT_SENSOR_PIN, INPUT);
  
  //////////// motor
  pinMode(MOTOR_RIGHT_PIN1, OUTPUT);
  pinMode(MOTOR_RIGHT_PIN2, OUTPUT);
  pinMode(MOTOR_LEFT_PIN1, OUTPUT);
  pinMode(MOTOR_LEFT_PIN2, OUTPUT);
  
  // encoder
   pinMode(encoderPinA, INPUT);
  }




/////////////////////////////////////////////////////////////////////////encoder




void setup() {
  Serial.begin(115200);
  
  pinmodes();
  
 initgyro();
 anglez = 0;  // تعيين الزاوية إلى صفر عند بدء التشغيل
 lasttime = millis();  // تعيين الوقت الأولي
  
 
  // تهيئة المتاهة
/////  bfs(centerPoints); // تشغيل BFS من مراكز المتاهة

  // Attach interrupt to encoder pins
  // attachInterrupt(digitalPinToInterrupt(encoderPinA), ISR_encoder, RISING);

 

}



void loop() {
    while (maze[robot_x][robot_y] != 0) {
    updateWalls(robot_x, robot_y, direction);
    bfs(centerPoints);
    moveToBestCell(robot_x, robot_y, direction);
    
    
   /*  // encoder//////////////////////////////////////////////
  float distancePerPulse = wheelCircumference / PPR;
 float distanceTraveled = pulseCount * distancePerPulse;

  // Print the distance traveled
  Serial.print("Distance Traveled: ");
  Serial.print(distanceTraveled);
  Serial.println(" cm");
*/
  // Add a small delay to avoid flooding the serial monitor
  
  delay(1000);
    }
 //////////////////////////////////////////////////////////////
 
////////////////////////////////////////////////////////////////////
  }
