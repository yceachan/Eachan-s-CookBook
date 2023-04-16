/*
 Name:    Bluetooth.ino
 Created: 2022//11/17
 Author:  Eachan
*/
#include <SoftwareSerial.h> //软件串口库——用io空模拟通信串口
#include<Arduino.h>

//argc1为蓝牙设备的txd，argc2为蓝牙的rxd
SoftwareSerial HC08(A0, A1); 


char foo;  //通信变量
String bar="";
void setup() {
  Serial.begin(115200);   
  HC08.begin(115200); 
  bar=new char[20];
}
 

void loop() {

 HC08.print("08wrint..\n");
 delay(1000);
  
}