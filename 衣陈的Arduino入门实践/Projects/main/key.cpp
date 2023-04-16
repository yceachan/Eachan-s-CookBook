#include<Arduino.h>
#include<pins_arduino.h>
#include"key.h"
#include"List.h"

List buffer;
const char key[N][N]={
  {'/','*','-','+'},
  {'7','8','9','C'},
  {'4','5','6','B'},
  {'1','2','3','0'}
};
const int row[N]={9,8,7,6};
const int col[N]={10,11,12,13};

//键盘初始设置：列线下拉为输出模式，行线上拉，按键独热码：0
void key_setup()
{
  for(int i=0;i<N;i++) pinMode(row[i],INPUT_PULLUP);
  for(int j=0;j<N;j++) pinMode(col[j],OUTPUT);
}

/**
*扫描键盘算法：依次为列线写入独热码0111,0100,0010,0001，读入行线电平可判断按压事件，在不可重队列中记录坐标，绑定计时器，扫描周期33ms，可覆盖debounce时间
*/
void keyscan()
{
  for(int i=0;i<N;i++) digitalWrite(col[i],1);
  for(int j=0;j<N;j++)
  {
    digitalWrite(col[j],0);
    for(int i=0;i<N;i++)
    {
      if(!digitalRead(row[i])) 
      {
        buffer.push(i, j);
      }
    }
    digitalWrite(col[j],1);
  }
}