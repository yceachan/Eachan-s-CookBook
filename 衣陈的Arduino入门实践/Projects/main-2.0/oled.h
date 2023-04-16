#include <U8g2lib.h>
 
#define Width 128
#define Height 64
#define px    12

extern U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2;    //Low spped I2C

void Oled_setup();
void stateDraw();
void uiDraw(); 
void OledDraw();
void pwdDraw();