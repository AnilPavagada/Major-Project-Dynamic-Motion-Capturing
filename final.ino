#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu1;
MPU6050 mpu2;

void setup() 
{
  Serial.begin(9600);
  Wire.begin();
  
  // Initialize MPU6050 sensors
  mpu1.initialize();
  mpu2.initialize();
  
  // Wait for Serial to initialize
  while (!Serial);
  
  // Print headers for Serial Plotter
  Serial.println("Sensor 1\tSensor 2");
  Serial.println("ax1,ay1,az1\tax2,ay2,az2");
}

void loop() {
  // Read data from MPU6050 sensor 1
  int16_t ax1, ay1, az1;
  int16_t gx1, gy1, gz1;
  mpu1.getMotion6(&ax1, &ay1, &az1, &gx1, &gy1, &gz1);

  // Read data from MPU6050 sensor 2
  int16_t ax2, ay2, az2;
  int16_t gx2, gy2, gz2;
  mpu2.getMotion6(&ax2, &ay2, &az2, &gx2, &gy2, &gz2);

  // Print sensor data for Serial Plotter
  Serial.print(ax1);
  Serial.print(",");
  Serial.print(ay1);
  Serial.print(",");
  Serial.print(az1);
  Serial.print("\t");
  Serial.print(ax2);
  Serial.print(",");
  Serial.print(ay2);
  Serial.print(",");
  Serial.println(az2);

  delay(100); // Adjust delay according to your needs
}