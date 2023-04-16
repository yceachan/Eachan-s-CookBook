#include<Arduino.h>
#include<pins_arduino.h>
#include"key.h"
#include"Timer1.h"

List buffer;
const char key[N][N]={
  {'/','*','-','+'},
  {'7','8','9','C'},
  {'4','5','6','B'},
  {'1','2','3','0'}
};

const u8 row[N]={9,8,7,6};
const u8 col[N]={10,11,12,13};
u32        clc[N][N]={0};

void key_scan()
{
  for(int i=0;i<N;i++) digitalWrite(col[i],1);

  for(int j=0;j<N;j++)
  {
    digitalWrite(col[j],0);
    for(int i=0;i<N;i++)
    {
      if(!digitalRead(row[i])) 
      {
        buffer.push(i,j);
        clc[i][j]=T1millis();
      }
    }
    digitalWrite(col[j],1);
  }
}
void key_setup()
{
  for(int i=0;i<N;i++) pinMode(row[i],INPUT_PULLUP);
  for(int j=0;j<N;j++) pinMode(col[j],OUTPUT);
}