/**
 * 程序功能：BT05(AT09)示例代码，不配置蓝牙运行
 * 使用教程：https://blog.yyzt.site/
 * 注意事项：无
 * 参考资料：1.https://blog.yyzt.site/ 参考相关蓝牙资料
 */

#include <Arduino.h>         // 导入Arduino库文件
#include <SoftwareSerial.h>  // 导入SoftwareSerial库文件

#define debugState true             // 串口调试打印状态，true--开启调试打印，false--关闭调试打印
#define debugSerial Serial          // 调试打印的串口
#define debugSerialBuadrate 115200  // 调试打印的串口波特率

#define bluetoothTxPin 27  // ESP32开发板的27号引脚接蓝牙模块的Tx引脚
#define bluetoothRxPin 26  // ESP32开发板的26号引脚接蓝牙模块的Rx引脚
#define workBaudrate 9600  // 蓝牙正常运行时与开发板通信的波特率（如果有重置蓝牙模块的波特率，则需要保持一致！！！）

SoftwareSerial bluetooth(bluetoothTxPin, bluetoothRxPin);  // 蓝牙软串口实例化
#define bluetoothSerial bluetooth                          // 蓝牙连接的串口

/**
 * 函数功能：程序初始化时调用，仅执行一次
 * 参数：无
 * 返回值：无
 * 注意事项：无
 */
void setup() {
  delay(1000);  // 延迟1000ms，等待各设备上电稳定

#if debugState
  debugSerial.begin(debugSerialBuadrate);  // 初始化调试打印的串口
#endif

  bluetoothSerial.begin(workBaudrate);  // 设置蓝牙正常运行时与设备通信的波特率

#if debugState
  debugSerial.println(F("\r\n程序初始化完成，开始接收/发送蓝牙数据......"));
#endif
}

/**
 * 函数功能：程序主循环函数，重复运行
 * 参数：无
 * 返回值：无
 * 注意事项：无
 */
void loop() {
  // 蓝牙上电后不需要自动配置，直接使用串口接收/发送数据
  if (bluetoothSerial.available() > 0) {                     // 如果串口缓存区有数据
    String readData = bluetoothSerial.readStringUntil('&');  // 获取发送端发送的数据（可以往readStringUntil函数中添加一个截止字符参数，比如'&'，这样收到截止字符后立马返回数据，效率更高，推荐使用！）
    if (readData != "") {                                    // 如果数据不为空
#if debugState
      debugSerial.print(F("接收到蓝牙的数据为："));
      debugSerial.println(readData);  // 打印接收到的数据
#endif
      bluetoothSerial.println("data:" + readData);  // 再将接收到的数据发送给发送端
    }
  }
}
