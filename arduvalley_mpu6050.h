#ifndef arduvalley_mpu6050_h
#define arduvalley_mpu6050_h
#include<Arduino.h>
#include<Wire.h>

// here we put the prototype of the functions
void initialise_gyro();

int16_t read_accel_x_raw();
int16_t read_accel_y_raw();
int16_t read_accel_z_raw();

int16_t read_gyro_x_raw();
int16_t read_gyro_y_raw();
int16_t read_gyro_z_raw();

float read_temp_in_cel();
float read_orientation_x();
float read_orientation_y();

#endif
