# arduvalley_mpu6050
lightest version of mpu6050, reading raw data from the register of mpu6050

V1.0 
This is the simplest and lightest version of reading mpu6050 data with error log
Data read is raw data directly from the register of mpu6050
in order to get the value in angle and degree, divide accelerometer value by 180

dependencies : wire.h & rduino.h (Already included in arduino IDE)No need to import externally
