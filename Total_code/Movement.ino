#include "movement.h"

void moveForward(int distance) {
  /*
  const float Kp = 1.0;  // Proportional gain for feedback control
  const float targetAngle = 0.0;  // Target angle (straight line)
 while (LEFT_SENSOR_PIN.read() < distance || RIGHT_SENSOR_PIN.read() < distance) {
  // get angle
   float angle;

   float angleError = targetAngle - angle;
    // Simple proportional control
    int output = Kp * angleError;
     // Ensure the adjustment is within valid PWM range
    output = constrain(output, -255, 255);
    // Control motors
    int leftSpeed = 255 - output;
    int rightSpeed = 255 + output;

    // Ensure motor speeds are within valid range
    leftSpeed = constrain(leftSpeed, 0, 255);
    rightSpeed = constrain(rightSpeed, 0, 255);

    // Set motor speeds
    analogWrite(MOTOR_RIGHT_PIN1, rightSpeed);
    analogWrite(MOTOR_RIGHT_PIN2, LOW);
    analogWrite(MOTOR_LEFT_PIN1, leftSpeed);
    analogWrite(MOTOR_LEFT_PIN2, LOW);

    delay(10);  // Small delay for stability

  }
  digitalWrite(MOTOR_RIGHT_PIN1, LOW);
  digitalWrite(MOTOR_RIGHT_PIN2, LOW);
  digitalWrite(MOTOR_LEFT_PIN1, LOW);
  digitalWrite(MOTOR_LEFT_PIN2, LOW);

 */
}

void turnLeft() {
  // إعادة تعيين المشفرات قبل الحركة
 /*
  while (abs(LEFT_SENSOR_PIN.read()) < 200 || abs(RIGHT_SENSOR_PIN.read()) < 200) {
    // استمر بالدوران حتى يتحقق الالتفاف بناءً على قراءات المشفرات
  }
  
 
   while (LEFT_SENSOR_PIN.read() < distance || RIGHT_SENSOR_PIN.read() < distance) {
    while(//gyro angle<90)
    {
      
  digitalWrite(MOTOR_RIGHT_PIN1, LOW);
  digitalWrite(MOTOR_RIGHT_PIN2, LOW);
  digitalWrite(MOTOR_LEFT_PIN1, LOW);
  digitalWrite(MOTOR_LEFT_PIN2, LOW);
      //gyro reading}
    }
  digitalWrite(MOTOR_RIGHT_PIN1, LOW);
  digitalWrite(MOTOR_RIGHT_PIN2, LOW);
  digitalWrite(MOTOR_LEFT_PIN1, LOW);
  digitalWrite(MOTOR_LEFT_PIN2, LOW);
  */
}

void turnRight() {
  
  
  //while (abs(leftEncoder.read()) < 200 || abs(rightEncoder.read()) < 200) {
    // استمر بالدوران حتى يتحقق الالتفاف بناءً على قراءات المشفرات
  }
