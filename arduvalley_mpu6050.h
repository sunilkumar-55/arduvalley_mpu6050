#ifndef arduvalley_mpu6050_h
#define arduvalley_mpu6050_h
#include<Arduino.h>
#include<Wire.h>

// here we put the prototype of the functions
void initialise_gyro();

int16_t read_accel_x();
int16_t read_accel_y();
int16_t read_accel_z();

int16_t read_gyro_x();
int16_t read_gyro_y();
int16_t read_gyro_z();

float read_temp_in_cel();


#endif