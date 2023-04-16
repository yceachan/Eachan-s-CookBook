#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

BLEServer *pServer = NULL;
BLECharacteristic * pCharacteristic=0;
bool deviceConnected = false;
bool oldDeviceConnected = false;
BLEService *pService=0;

#define SERVICE_UUID         "00004396-0000-1000-8000-00805F9B34FB" // UART service UUID
#define CHARACTERISTIC_UUID "00004396-0000-1000-8000-00805F9B34FB"

String datar="";
#define ServoPin 9
void ServoControl(int servoAngle);
void setup()
{
  pinMode(9,OUTPUT);
}

void loop() {
 for(int i=0;i<180;i+=30) 
 {
   ServoControl(i);   
   delay(1000);
 }
  for(int i=180;i>0;i-=30) 
 {
   ServoControl(i);   
   delay(1000);
 }
}
/*
*舵机驱动代码，经测量，舵机模块0至180度转角映射pwm脉冲宽度为615-2500,
*定频调宽，调制周期20ms，脉冲宽度/占空比为角度映射值，频率为50hz的pwm信号
*/
void ServoControl(int servoAngle)
{
  double pwmval = map(servoAngle, 0, 180, 615, 2500);//等比例角度值范围转换高电平持续时间范围
  
  unsigned char i = 50;//50Hz 每秒的周期次数(周期/秒) 即1S 50 个周期 每个周期20ms
  while (i--)
  {
    digitalWrite(ServoPin,HIGH);
    delayMicroseconds(pwmval); //高电平时间
    Serial.print(i);
    digitalWrite(ServoPin,LOW);
    delayMicroseconds(20000 - pwmval);//每个周期20ms减去高电平持续时间
  }
}