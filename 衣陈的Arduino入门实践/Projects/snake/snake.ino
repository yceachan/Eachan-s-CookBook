#include <Arduino.h>
#include <U8g2lib.h>
#include"snake.h"
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif
#define Width 128
#define Height 64
#define px    12 
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);    //Low spped I2C
Snake player;
void setup(void) {
  u8g2.begin();
  player.Init();
}
void loop()
{
  player.Move();
  player.Draw();
}
Snake::Snake()
{
  size=0;
}
void Snake::push()
{
  node* tail=&this->m_snake[size-1];
  size++;
  this->m_snake[size-1].dir=tail->dir;
  switch(tail->dir)
  {
    case UP:
      this->m_snake[size-1].x=tail->x;
      this->m_snake[size-1].y=tail->y+1;
      break;
    case DOWN:
      this->m_snake[size-1].x=tail->x;
      this->m_snake[size-1].y=tail->y-1;
      break;
    case LEFT:
      this->m_snake[size-1].x=tail->x+1;
      this->m_snake[size-1].y=tail->y;
      break;
    case RIGHT:
      this->m_snake[size-1].x=tail->x-1;
      this->m_snake[size-1].y=tail->y;
      break;
  }
}
void Snake::Init()
{ 
  size++;
  this->m_snake[size-1].x= rand() % (WID-6) + 3;
  this->m_snake[size-1].y= rand() % (HEI-6) + 3;
  this->m_snake[size-1].dir=rand() % 4;
  this->push();
  this->push();
}
void Snake::Move()
{
  for(int i=this->size-1;i>0;i--)
  {
    m_snake[i].x=m_snake[i-1].x;
    m_snake[i].y=m_snake[i-1].y;
    m_snake[i].dir=m_snake[i-1].dir;
  }
  switch(m_snake[0].dir)
  {   
    case UP:
        m_snake[0].y-=1;break;
    case DOWN:
        m_snake[0].y+=1;break;
    case LEFT:
        m_snake[0].x-=1;break;
    case RIGHT:
        m_snake[0].x+=1;break;
  }
}
void Snake::Draw()
{
  for(int i=0;i<size;i++)
  {
    u8g2.drawBox(m_snake[i].x*2,m_snake[i].y*2,2,2);
  }
}