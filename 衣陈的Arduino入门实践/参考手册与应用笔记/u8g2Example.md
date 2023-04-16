~~~C++
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
 
 U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);    //Low spped I2C
 
void setup(void) {
  u8g2.begin();
}
void stateDraw();
void uiDraw(); 
void loop(void) {
  u8g2.clearBuffer();                   // clear the internal memory
  stateDraw();
  uiDraw();
  u8g2.sendBuffer();                    // transfer internal memory to the display
  delay(1000);  
}
void uiDraw()
{
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(0,1.3*px,"Password:");
  u8g2.drawFrame(1.5*px  ,1.5*px+2  ,Width-3*px  ,Height-2*px-4 );
  u8g2.drawFrame(1.5*px-1,1.5*px+2-1,Width-3*px+2,Height-2*px-4+2); 
}
void stateDraw()
{
  u8g2.setFont(u8g2_font_waffle_t_all);   // choose a suitable font
  u8g2.drawGlyph(Width-1*px,px,0xe253);    //电量
  u8g2.drawGlyph(Width-2*px,px,0xe21a);//wifi
  u8g2.drawGlyph(Width-3*px,px,0xe0f0);  //信号
  u8g2.drawGlyph(Width-4*px,px,0xe1b5);  //蓝牙
}
#define beg 1.5*px+2
void KeyDraw()
{
  static pos=0;
}
~~~

