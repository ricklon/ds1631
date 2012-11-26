/*
*
 * DS1631_CPP Library Example
 *
 *
 *
 */

#include <Wire.h>
#include "DS1631.h"

uint8_t conf = 0x0C;
uint8_t dev1 = DEV0;  

DS1631 Tmp1(dev1); //Wire.begin hasn't happened yet

void setup()
{
  Serial.begin(9600);
  Wire.begin();

  Tmp1.stopConversion();
  Tmp1.setConfig(conf);
  byte config = Tmp1.getConfig();
  Serial.print("Config: dev:");
  Serial.print(DEV0, BIN);
  Serial.print(" set: ");
  Serial.print(config, BIN);
  Serial.print(conf, BIN);
  Serial.print(" get: ");
  Serial.println(config, BIN);
}

void loop()
{
  float temp = Tmp1.getTemp();
  Serial.print("TempC: ");
  Serial.print(temp, 4);
  Serial.print(" tempF: ");
  Serial.println((temp*9/5) + 32, 4);
}



