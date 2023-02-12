#include "arduvalley_mpu6050.h"

// Global_var
const int MPU_addr = 0x68; // MPU6050 I2C address
byte error;
int16_t temp;
float temp_in_cel; //for reading temperature in celsius


//definition of all the function
void initialise_gyro()
{
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B); // power management 1
  Wire.write(0x00);
  Wire.endTransmission(true);

  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6c); // standby mode of particular hardware
  Wire.write(0x00);
  Wire.endTransmission(true);

  Wire.beginTransmission(MPU_addr);
  Wire.write(0x1C); // accelerometer configuration
  Wire.write(0b00000000);
  Wire.endTransmission(true);
  delay(100);
}

int16_t read_accel_x_raw()
{ // for reading accel_x
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);
  error = Wire.endTransmission(false);
  if (error != 0)
  {
    Serial.println("ERROR DURING READING");
  }
  Wire.requestFrom(MPU_addr, 2, true);
  if (Wire.available() == 2)
  {
    temp = Wire.read() << 8;
    temp |= Wire.read();
  }
  else
  {
    Serial.println("data not equal to two byte");
  }
  return temp;
}

int16_t read_accel_y_raw()
{ // for reading accel_y
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3D);
  error = Wire.endTransmission(false);
  if (error != 0)
  {
    Serial.println("ERROR DURING READING");
  }
  Wire.requestFrom(MPU_addr, 2, true);
  if (Wire.available() == 2)
  {
    temp = Wire.read() << 8;
    temp |= Wire.read();
  }
  else
  {
    Serial.println("data not equal to two byte");
  }
  return temp;
}

int16_t read_accel_z_raw()
{ // for reading accel_z
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3F);
  error = Wire.endTransmission(false);
  if (error != 0)
  {
    Serial.println("ERROR DURING READING");
  }
  Wire.requestFrom(MPU_addr, 2, true);
  if (Wire.available() == 2)
  {
    temp = Wire.read() << 8;
    temp |= Wire.read();
  }
  else
  {
    Serial.println("data not equal to two byte");
  }
  return temp;
}

int16_t read_gyro_x_raw()
{ // for reading gyro_x
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x43);
  error = Wire.endTransmission(false);
  if (error != 0)
  {
    Serial.println("ERROR DURING READING");
  }
  Wire.requestFrom(MPU_addr, 2, true);
  if (Wire.available() == 2)
  {
    temp = Wire.read() << 8;
    temp |= Wire.read();
  }
  else
  {
    Serial.println("data not equal to two byte");
  }
  return temp;
}

int16_t read_gyro_y_raw()
{ // for reading gyro_y
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x45);
  error = Wire.endTransmission(false);
  if (error != 0)
  {
    Serial.println("ERROR DURING READING");
  }
  Wire.requestFrom(MPU_addr, 2, true);
  if (Wire.available() == 2)
  {
    temp = Wire.read() << 8;
    temp |= Wire.read();
  }
  else
  {
    Serial.println("data not equal to two byte");
  }
  return temp;
}

int16_t read_gyro_z_raw()
{ // for reading accel_z
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x47);
  error = Wire.endTransmission(false);
  if (error != 0)
  {
    Serial.println("ERROR DURING READING");
  }
  Wire.requestFrom(MPU_addr, 2, true);
  if (Wire.available() == 2)
  {
    temp = Wire.read() << 8;
    temp |= Wire.read();
  }
  else
  {
    Serial.println("data not equal to two byte");
  }
  return temp;
}

float read_temp_in_cel()
{
  // for reading temp in celsius
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x41);
  error = Wire.endTransmission(false);
  if (error != 0)
  {
    Serial.println("ERROR DURING READING");
  }
  Wire.requestFrom(MPU_addr, 2, true);
  if (Wire.available() == 2)
  {
    temp = Wire.read() << 8;
    temp |= Wire.read();
    temp_in_cel = (temp/340) + 36.53;
  }
  else
  {
    Serial.println("data not equal to two byte");
  }

  return temp_in_cel;
}

float read_orientation_x()
{
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr, 6);

  temp = Wire.read() << 8;
  temp |= Wire.read();
  int16_t read_x = temp;

  temp = Wire.read() << 8;
  temp |= Wire.read();
  int16_t read_y = temp;

  temp = Wire.read() << 8;
  temp |= Wire.read();
  int16_t read_z = temp;

  float read_accel_x = atan2(read_y, read_z) * 180.0 / PI;

  return read_accel_x;
}

float read_orientation_y()
{
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr, 6);
  
  int t = Wire.read();
  float read_x = (t << 8) | Wire.read();
  t = Wire.read();
  float read_y = (t << 8) | Wire.read();
  t = Wire.read();
  float read_z = (t << 8) | Wire.read();
  float read_accel_y = atan2(-read_x , sqrt(read_y * read_y + read_z * read_z)) * 180.0 / PI; //account for roll already applied
  return read_accel_y;
}