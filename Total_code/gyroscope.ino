#include "gyroscope.h"

  float anglez = 0, offset1 = 0, offset2 = 0, offset3 = 0.0f,   lasttime = 0, dt;
float area = 0;

Adafruit_MPU6050 mpu;
sensors_event_t a, g, temp;

void initgyro() {
  // تهيئة MPU6050
  mpu.begin();
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  while (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    delay(10);
  }
  Serial.println("MPU6050 Found!");

  // Calibration (معايرة الجايروسكوب)
  for (int i = 0; i < 200; i++) {
    mpu.getEvent(&a, &g, &temp);
   // offset1 += g.gyro.x;
   // offset2 += g.gyro.y;
    offset3 += g.gyro.z;
  }
 // offset1 /= 200.0;
 // offset2 /= 200.0;
  offset3 /= 200.0;
}

void readgyro() {
  float time = millis();
  dt = (time - lasttime) / 1000.0;  // احسب الزمن المنقضي بالثواني
  
  mpu.getEvent(&a, &g, &temp);
  area = (g.gyro.z - offset3) * dt * 180 / M_PI;  // حساب التغيير في الزاوية
  
  if (fabs(area) > 0.04) {
    anglez += area;
  }
  
  lasttime = time;

  Serial.print("anglez = ");
  Serial.println(anglez);
}
