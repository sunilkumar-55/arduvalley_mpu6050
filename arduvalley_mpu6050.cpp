#include "arduvalley_mpu6050.h"
// Global_var
const int MPU_addr = 0x68; // MPU6050 I2C address
byte error;
int16_t temp;
float temp_in_cel;

// Here we will put the definition of the function
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

int16_t read_accel_x()
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

int16_t read_accel_y()
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

int16_t read_accel_z()
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

int16_t read_gyro_x()
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

int16_t read_gyro_y()
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

int16_t read_gyro_z()
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
    temp_in_cel = temp/340 + 36.53;
  }
  else
  {
    Serial.println("data not equal to two byte");
  }

  return temp_in_cel;
}