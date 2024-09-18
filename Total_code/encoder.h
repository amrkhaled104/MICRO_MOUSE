#ifndef ENCODER_FUNCTIONS_H
#define ENCODER_FUNCTIONS_H

#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <math.h>

const int encoderPinA = 2; 

/////////////////encoder var///////////////////
const int PPR = 20; // Pulses per revolution
const float wheelDiameter = 10.0; // Diameter of the wheel in cm
const float wheelCircumference = 3.14159 * wheelDiameter; // Circumference of the wheel

// Variables to store pulse counts
volatile long pulseCount = 0;

// Interrupt service routine for encoder

#endif
