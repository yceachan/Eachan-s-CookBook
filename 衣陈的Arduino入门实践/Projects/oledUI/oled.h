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

extern U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2;    //Low spped I2C
void oled_setup();
void stateDraw();
void uiDraw(); 
void oledDraw();