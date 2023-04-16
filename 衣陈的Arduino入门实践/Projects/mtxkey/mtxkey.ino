#include <MsTimer2.h>

#include"Int_cycleList.h"
#define N 4
#define DELAY 25
typedef unsigned long u32;
const char key[N][N]={
  {'/','*','-','+'},
  {'7','8','9','C'},
  {'4','5','6','B'},
  {'1','2','3','A'}
};
const byte row[N]={2,3,4,5};
const byte col[N]={8,9,10,11};
u32        clc[N][N]={0};
List buffer;
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
        clc[i][j]=millis();
      }
    }
    digitalWrite(col[j],1);
  }
}
char keypop()
{
  pair cur=buffer.front();
  int r=cur.r,c=cur.c;
  if(digitalRead(row[r])&& millis()-clc[r][c]>DELAY)
  {
    buffer.pop();
    return key[r][c];
  }
  else return 0;
}
void setup()
{
  Serial.begin(9600);
  for(int i=0;i<N;i++) pinMode(row[i],INPUT_PULLUP);
  for(int j=0;j<N;j++) pinMode(col[j],OUTPUT);
  MsTimer2::set(200,keyscan);
  MsTimer2::start();
}
void loop()
{
 // keyscan();
  char val=keypop();
  if(val)
  {
    Serial.println(val);
  }
}