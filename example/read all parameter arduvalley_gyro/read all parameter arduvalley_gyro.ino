#include <arduvalley_mpu6050.h>
int16_t accel_x, accel_y, accel_z, gyro_x, gyro_y, gyro_z;
float temp_data;

void setup() {
  Serial.begin(115200);
  initialise_gyro();
  delay(200);
}

void loop() {
  accel_x = read_accel_x();
  accel_y = read_accel_y();
  accel_y = read_accel_z();

  gyro_x = read_gyro_x();
  gyro_y = read_gyro_y();
  gyro_z = read_gyro_z();

  float a = read_temp_in_cel();

  Serial.println(accel_x);
  Serial.println(accel_y);
  Serial.println(accel_z);

  Serial.println(gyro_x);
  Serial.println(gyro_y);
  Serial.println(gyro_z);
}
