#include<Wire.h>

const int mpu6050_addr=0x68;
int16_t GyX,GyY,GyZ;

void setup() {
Serial.begin(115200);
Wire.begin();

Wire.beginTransmission(mpu6050_addr);
Wire.write(0x6b);
Wire.write(0);
Wire.endTransmission(true);
}

void loop() {
  Wire.beginTransmission(mpu6050_addr);
  Wire.write(0x43);
  Wire.endTransmission(false);
  Wire.requestFrom(mpu6050_addr ,6, true);
  GyX=Wire.read()<<8;Wire.read();
  GyY=Wire.read()<<8;Wire.read();
  GyZ=Wire.read()<<8;Wire.read();

  static int cnt_loop;
  cnt_loop++;
  if(cnt_loop%200!=0) return;

  Serial.print("Gyx = "); Serial.print(GyX);
  Serial.print(" : GyY = "); Serial.print(GyY);
  Serial.print(" : GyZ = "); Serial.print(GyZ);
  Serial.println();
}
