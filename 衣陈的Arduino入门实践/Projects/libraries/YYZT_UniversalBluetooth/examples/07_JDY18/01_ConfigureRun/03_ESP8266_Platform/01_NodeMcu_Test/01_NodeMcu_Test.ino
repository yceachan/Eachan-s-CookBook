/**
 * 程序功能：JDY18示例代码，配置蓝牙后运行
 * 使用教程：https://blog.yyzt.site/
 * 注意事项：无
 * 参考资料：1.https://blog.yyzt.site/ 参考相关蓝牙资料
 */

#include <Arduino.h>                  // 导入Arduino库文件
#include <SoftwareSerial.h>           // 导入SoftwareSerial库文件
#include <YYZT_UniversalBluetooth.h>  // 导入YYZT_UniversalBluetooth库文件

#define debugState true             // 串口调试打印状态，true--开启调试打印，false--关闭调试打印
#define debugSerial Serial          // 调试打印的串口
#define debugSerialBuadrate 115200  // 调试打印的串口波特率

#define bluetoothTxPin 14                              // NodeMcu开发板的14引脚(D5)接蓝牙模块的Tx引脚
#define bluetoothRxPin 12                              // NodeMcu开发板的12引脚(D6)接蓝牙模块的Rx引脚
#define configureTimeout 20000                         // 蓝牙配置超时时间，20秒
#define singleStepTimeout 2000                         // 蓝牙单步配置超时时间，2秒
#define resetBaudrate 9600                             // 重置蓝牙模块的波特率（如果不需要重置蓝牙模块波特率则不调用相关函数即可）
#define workBaudrate 9600                              // 蓝牙正常运行时与开发板通信的波特率（如果有重置蓝牙模块的波特率，则需要保持一致！！！）
#define bluetoothName "JDY18"                          // 蓝牙的名称（18字符内）
#define bluetoothPassword "123456"                     // 蓝牙的配对连接密码（6位数）
#define bluetoothType JDY18_TypeNoBindingWithPassword  // 蓝牙蓝牙密码连接方式，这是配置为有密码连接
#define bluetoothRole JDY18_SlaveRole                  // 蓝牙角色，JDY18_SlaveRole--从机（APP、微信、小程序透传）

SoftwareSerial bluetooth(bluetoothTxPin, bluetoothRxPin);  // 蓝牙软串口实例化
JDY18 jdy18;                                               // 蓝牙配置实例化
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

  bluetoothSerial.begin(workBaudrate);                 // 设置蓝牙正常运行时与设备通信的波特率
  jdy18.setSerial(bluetoothSerial);                    // 设置蓝牙连接的串口
  jdy18.setAllConfigureTimeout(configureTimeout);      // 设置蓝牙总配置超时时间
  jdy18.setSingleConfigureTimeout(singleStepTimeout);  // 设置蓝牙单步配置超时时间
  // jdy18.resetBluetoothBaudrate(resetBaudrate);         // 重置蓝牙模块的波特率（如果不需要重置蓝牙模块波特率则不使用，注释即可）
  jdy18.setName(bluetoothName);          // 设置蓝牙的名称（18字符内）
  jdy18.setPassword(bluetoothPassword);  // 设置蓝牙的配对连接密码（6位数）
  jdy18.setType(bluetoothType);          // 设置蓝牙密码连接方式
  jdy18.setRole(bluetoothRole);          // 设置蓝牙的角色
  jdy18.startConfigure();                // 开始配置蓝牙参数

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
  if (jdy18.getConfigureState() == Configuring) {           // 如果蓝牙配置状态为正在配置中
    jdy18.configureRuning();                                // 配置蓝牙参数
    if (jdy18.getConfigureState() == ConfigureSucceeded) {  // 如果蓝牙配置状态为配置成功
#if debugState
      debugSerial.println(F("蓝牙配置成功！"));
#endif
    } else if (jdy18.getConfigureState() == ConfigureFailed) {  // 如果蓝牙配置状态为配置失败
#if debugState
      debugSerial.println(F("蓝牙配置失败！请检查蓝牙是否未断开当前连接或者其他问题！"));
#endif
    }
  }

  // 蓝牙配置成功后即可接收/发送数据
  if (jdy18.getConfigureState() == ConfigureSucceeded) {       // 如果蓝牙配置状态为配置成功
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
