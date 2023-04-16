/**
 * 程序功能：HC05示例代码，配置蓝牙后运行
 * 使用教程：https://blog.yyzt.site/
 * 注意事项：1.HC05蓝牙进入AT模式需要上电前按住EN按键不放，上电后直到AT指令设置完成，才能松开EN按键
 *          2.HC05原装版（全新版）配置完AT指令后，蓝牙需要重新上电才生效
 * 参考资料：1.https://blog.yyzt.site/ 参考相关蓝牙资料
 */

#include <Arduino.h>                  // 导入Arduino库文件
#include <SoftwareSerial.h>           // 导入SoftwareSerial库文件
#include <YYZT_UniversalBluetooth.h>  // 导入YYZT_UniversalBluetooth库文件

#define debugHardwareSerialRxPin PA10                                                    // STM32F103C8T6的A10引脚（PA10）,串口接收引脚（RX）
#define debugHardwareSerialTxPin PA9                                                     // STM32F103C8T6的A9引脚（PA9）,串口发送引脚（TX）
HardwareSerial debugHardwareSerial(debugHardwareSerialRxPin, debugHardwareSerialTxPin);  // 创建调试串口实例
#define debugState true                                                                  // 串口调试打印状态，true--开启调试打印，false--关闭调试打印
#define debugSerial debugHardwareSerial                                                  // 调试打印的串口
#define debugSerialBuadrate 115200                                                       // 调试打印的串口波特率

#define bluetoothTxPin PB9            // STM32F103C8T6开发板的PB9引脚接蓝牙模块的Tx引脚
#define bluetoothRxPin PB8            // STM32F103C8T6开发板的PB8引脚接蓝牙模块的Rx引脚
#define configureTimeout 20000        // 蓝牙配置超时时间，20秒
#define singleStepTimeout 1000        // 蓝牙单步配置超时时间，1秒
#define resetBaudrate 9600            // 重置蓝牙模块的波特率（如果不需要重置蓝牙模块波特率则不调用相关函数即可）
#define workBaudrate 9600             // 蓝牙正常运行时与开发板通信的波特率（如果有重置蓝牙模块的波特率，则需要保持一致！！！）
#define bluetoothName "HC05"          // 蓝牙的名称（32字符内）
#define bluetoothPassword "1234"      // 蓝牙的配对连接密码（4位数）
#define bluetoothRole HC05_SlaveRole  // 蓝牙的角色（HC05_SlaveRole--从机，HC05_MasterRole--主机，HC05_SlaveLoopRole--回环）
#define bluetoothCMODE HC05_AnyCMODE  // 蓝牙的连接模式（HC05_SpecifiedCMODE--指定蓝牙地址连接模式，HC05_AnyCMODE--任意蓝牙地址连接模式，HC05_SlaveLoopCMODE--回环角色连接模式）

SoftwareSerial bluetooth(bluetoothTxPin, bluetoothRxPin);  // 蓝牙软串口实例化
HC05 hc05;                                                 // 蓝牙配置实例化
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

  bluetoothSerial.begin(38400);                       // 设置蓝牙进行AT指令时的波特率
  hc05.setSerial(bluetoothSerial);                    // 设置蓝牙连接的串口
  hc05.setAllConfigureTimeout(configureTimeout);      // 设置蓝牙总配置超时时间
  hc05.setSingleConfigureTimeout(singleStepTimeout);  // 设置蓝牙单步配置超时时间
  // hc05.resetBluetoothBaudrate(resetBaudrate);         // 重置蓝牙模块的波特率（如果不需要重置蓝牙模块波特率则不使用，注释即可）
  hc05.setName(bluetoothName);          // 设置蓝牙的名称（32字符内）
  hc05.setPassword(bluetoothPassword);  // 设置蓝牙的配对连接密码（4位数）
  hc05.setRole(bluetoothRole);          // 设置蓝牙的角色
  hc05.setCMODE(bluetoothCMODE);        // 设置连接模式
  hc05.startConfigure();                // 开始配置蓝牙参数

#if debugState
  debugSerial.println(F("\r\n程序初始化完成，开始配置蓝牙......"));
#endif
}

/**
 * 函数功能：程序主循环函数，重复运行
 * 参数：无
 * 返回值：无
 * 注意事项：无
 */
void loop() {
  if (hc05.getConfigureState() == Configuring) {           // 如果蓝牙配置状态为正在配置中
    hc05.configureRuning();                                // 配置蓝牙参数
    if (hc05.getConfigureState() == ConfigureSucceeded) {  // 如果蓝牙配置状态为配置成功
#if debugState
      debugSerial.println(F("蓝牙配置成功！"));
#endif
      bluetoothSerial.begin(workBaudrate);                     // 设置蓝牙正常运行时与设备通信的波特率
    } else if (hc05.getConfigureState() == ConfigureFailed) {  // 如果蓝牙配置状态为配置失败
#if debugState
      debugSerial.println(F("蓝牙配置失败！请检查蓝牙是否未断开当前连接或者其他问题！"));
#endif
    }
  }

  // 蓝牙配置成功后即可接收/发送数据
  if (hc05.getConfigureState() == ConfigureSucceeded) {        // 如果蓝牙配置状态为配置成功
    if (bluetoothSerial.available() > 0) {                     // 如果串口缓存区有数据
      String readData = bluetoothSerial.readStringUntil('&');  // 获取发送端发送的数据（可以往readStringUntil函数中添加一个截止字符参数，比如'&'，这样收到截止字符后立马返回数据，效率更高，推荐使用！）
      if (readData != "") {                                    // 如果数据不为空
#if debugState
        debugSerial.print(F("接收到的数据为："));
        debugSerial.println(readData);  // 打印接收到的数据
#endif
        bluetoothSerial.println("data:" + readData);  // 再将接收到的数据发送给发送端
      }
    }
  }
}
