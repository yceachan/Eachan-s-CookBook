3.1蓝牙模块配对程序
/*******************************************************************************************
 * A BLE client example that is rich in capabilities.
 * There is a lot new capabilities implemented.
 * Here using GATT to simulate the UART communication with Ea_HC08,whose UUID is "4396"。 
 * annotator  Ea_chan
 *******************************************************************************************/
#include<Arduino.h>
#include <BLEDevice.h>
//#include "BLEScan.h"
// The remote service we wish to connect to.
static BLEUUID serviceUUID("00004396-0000-1000-8000-00805F9B34FB");
// The characteristic of the remote service we are interested in.
static BLEUUID    charUUID("00004396-0000-1000-8000-00805F9B34FB");

static boolean doConnect = false;
static boolean connected = false;
static boolean doScan = false;
static BLERemoteCharacteristic* pRemoteCharacteristic;
static BLEAdvertisedDevice* myDevice;
String datar="";

//关于连接成功和断开连接的一些回调函数，触发对应中断后执行相应回调
class MyClientCallback : public BLEClientCallbacks 
{
    void onConnect(BLEClient* pclient) {/***/}

    void onDisconnect(BLEClient* pclient) {
        connected = false;
        Serial.println("onDisconnect");
        }
};
/**
*  核心函数，链接到目标服务器（HC08）
*  To form a connection to "myDevice->getAddress().toString().c_str());
*  核心语句 pClient->connect(myDevice); 
*/
bool connectToServer() 
{
    BLEClient*  pClient  = BLEDevice::createClient();
    pClient->setClientCallbacks(new MyClientCallback());

    pClient->connect(myDevice);  // i
    pClient->setMTU(517); //set client to request maximum MTU from server (default is 23 otherwise)  @MTX:（maximum transmission unit）最大传输单元

    // Obtain a reference to the service/eCharacteristic we are after in the remote BLE server.
    BLERemoteService* pRemoteService = pClient->getService(serviceUUID);
    if (pRemoteService == nullptr) {
        pClient->disconnect();
        return false;
    }
    pRemoteCharacteristic = pRemoteService->getCharacteristic(charUUID);
    if (pRemoteCharacteristic == nullptr) {
        pClient->disconnect();
        return false;
    }
    Serial.println(" - Found our characteristic");

    // Read the value of the characteristic.
    if(pRemoteCharacteristic->canRead()){
        std::string value = pRemoteCharacteristic->readValue();
        Serial.println(value.c_str());
    }

    if(pRemoteCharacteristic->canNotify())
        pRemoteCharacteristic->registerForNotify(notifyCallback);

    connected = true;
    return true;
}
/**
*Scan for BLE servers and find the first one that advertises the service
*we are looking for.
*/
class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks {
    void onResult(BLEAdvertisedDevice advertisedDevice) {
        if (advertisedDevice.haveServiceUUID() && advertisedDevice.isAdvertisingService(serviceUUID)) {

            BLEDevice::getScan()->stop();
            myDevice = new BLEAdvertisedDevice(advertisedDevice);
            doConnect = true;
            doScan = true;

        } 
    } 
};  

/**
*setup函数，初始化BLE设备信息（名称，工作模式，绑定回调，扫描间隔与时长）
*在start()是阻塞方法，负责循环扫描周围蓝牙设备直至扫描到目标UUID（“4396”）
*/
void setup() {
    pinMode(ServoPin,OUTPUT);
    Serial.begin(115200);
    BLEDevice::init("Ea_esp32");

    // Retrieve a Scanner and set the callback we want to use to be informed when we
    // have detected a new device.  Specify that we want active scanning and start the
    // scan to run for 5 seconds.
    BLEScan* pBLEScan = BLEDevice::getScan();
    pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
    pBLEScan->setInterval(1349);
    pBLEScan->setWindow(449);
    pBLEScan->setActiveScan(true);
    pBLEScan->start(5, false);//在start()是阻塞方法，负责循环扫描周围蓝牙设备直至扫描到目标UUID（“4396”）或超时返回 （5s
    
    if (doConnect == true) {
    if (connectToServer()) {
      Serial.println("We are now connected to the BLE Server.");
    } else {
      Serial.println("We have failed to connect to the server; there is nothin more we will do.");
    }
    doConnect = false;
  }
} 

3.2蓝牙模块GATT协议下模拟UART透传
3.2.1 esp32端
RX事件，即服务端对客户端的Notify（通知），在notify中断中串口打印接受数据，并将其赋值给全局变量datar
static void notifyCallback( BLERemoteCharacteristic* pBLERemoteCharacteristic,uint8_t* pData,size_t length,bool isNotify ) 
{
    Serial.println((char*)pData);
    datar=(char*)pData;
}
//loop回圈内处理datar，解算报文，驱动舵机完成开门动作
if(datar.length()>0)
    {
        if(strstr(datar.c_str(),"UNFOLD"))
        {
            ServoControl(180);
            delay(3000);
            ServoControl(0);
            datar="";
        }
}
Tx事件，简单调库即可
 if (connected) 
    {
         pRemoteCharacteristic-writeValue>("writings...");
}
3.2.2uno端//使用硬串口连接
void RXthing()
{
  Timeroff();//函数原型：TIMSK1 &= ~(1 << OCIE1A);//将TIMER1使能寄存器TIMSK1下时钟中断使能寄存器OCIE1位0 （即，关闭定时中断）
  if(Serial.available())
  {
      String TX=Serial.readString();
      Serial.print(TX.c_str());
  }
  Timer1on();//函数原型：TIMSK1 |= (1 << OCIE1A);//置1
}
void TXthing()
{
    static unsigned long it=0;
  unsigned time=millis();
  if(time-it>1000)
  {
      Timeroff();
      Serial.print(pwd);
      Serial.println(time);
      it=time;
      Timer1on();
  }
}
