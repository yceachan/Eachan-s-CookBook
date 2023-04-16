#include"oled.h"

 
 U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);    //Low spped I2C
void setup()
{
  oled_setup();
}
void loop()
{
  oledDraw();
}


