/*
*
 * DS1631 library object.
 * Articles used in reference for this:
 * http://www.maxim-ic.com/app-notes/index.mvp/id/135
 * http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1221926830
 * http://www.peyregne.info/wp/?p=211
 *
 * Registers R1, and R2 are used to set 9, 10, 11, 12 bit temperature resolution 
 * Between a range of -55C to +125C 
 * A0, A1, A2 are used to set the device address. Which is shifted by the library for use.
 * 1SHOT readings or Continuous Readings can be configured
 * 12 bit resolution can take up to 750ms to be available
 * Temperature is returned in a 16 bit  two's complement Th, and Tl Register
 * The signed bit S, S = 0 for positive, and S = 1 for negative
 */
 
#ifndef DS1631_h
#define DS1631_h

#if defined(ARDUINO) && ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

#define DEV0 0x90
#define DEV1 0x91
#define DEV2 0x92
#define DEV3 0x93
#define DEV4 0x94
#define DEV5 0x95
#define DEV6 0x96
#define DEV7 0x97

class DS1631 
{
public:

  DS1631(uint8_t _ADDR);
  ~DS1631();
  void begin( );
  byte getConfig();
  void setConfig(uint8_t _ADDR);
  float getTemp();
  void stopConversion();
  void startConversion();

  //TODO:
  uint8_t getTripHigh();
  void setTripHigh(uint8_t _ADDR);
  uint8_t getTripLow();
  void setTripLow(uint8_t _ADDR);

private:  
  float calcTemp(int msb,  int lsb);
  uint8_t _addr;
  uint8_t _temp[2];
};
#endif





