#include <Arduino.h>
#include <U8g2lib.h>
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif
#define Width 128
#define Height 64
#define px    12
//U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);  // High speed I2C
 
extern U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2;    //Low spped I2C
 
void Oled_setup();
void stateDraw();
void uiDraw(); 
void OledDraw();
void pwdDraw();