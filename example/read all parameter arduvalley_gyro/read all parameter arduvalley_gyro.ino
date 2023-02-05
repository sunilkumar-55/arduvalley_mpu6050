#include <arduvalley_mpu6050.h>
int16_t accel_x_raw, accel_y_raw, accel_z_raw, gyro_x_raw, gyro_y_raw, gyro_z_raw;
float temperature_in_celsius, acceleration_x_axis, acceleration_y_axis;

void setup() {
  Serial.begin(115200);
  initialise_gyro();
  delay(200);
}

void loop() {
  // accel_x_raw = read_accel_x_raw();
  // accel_y_raw = read_accel_y_raw();
  // accel_z_raw = read_accel_z_raw();

  // gyro_x_raw = read_gyro_x_raw();
  // gyro_y_raw = read_gyro_y_raw();
  // gyro_z_raw = read_gyro_z_raw();

  acceleration_x_axis = read_orientation_x();
  acceleration_y_axis = read_orientation_y();

  temperature_in_celsius = read_temp_in_cel();

  // Serial.print("accel_x_raw :: >> ");
  // Serial.println(accel_x_raw);
  // Serial.print("accel_y_raw :: >> ");
  // Serial.println(accel_y_raw);
  // Serial.print("accel_z_raw :: >> ");
  // Serial.println(accel_z_raw);

  // Serial.print("gyro_x_raw :: >> ");
  // Serial.println(gyro_x_raw);
  // Serial.print("gyro_y_raw :: >> ");
  // Serial.println(gyro_y_raw);
  // Serial.print("gyro_z_raw :: >> ");
  // Serial.println(gyro_z_raw);

  Serial.print("acceleration_x_axis :: >> ");
  Serial.println(acceleration_x_axis);
  Serial.print("acceleration_y_axis :: >> ");
  Serial.println(acceleration_y_axis);
  Serial.print("temperature_in_celsius :: >> ");
  Serial.println(temperature_in_celsius);
  delay(200);
}
