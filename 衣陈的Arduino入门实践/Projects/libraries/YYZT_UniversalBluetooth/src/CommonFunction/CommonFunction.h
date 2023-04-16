#ifndef COMMONFUNCTION_H
#define COMMONFUNCTION_H

#include <Arduino.h>
#include <Stream.h>

#define YYZT_abs(x) ((x) > 0 ? (x) : -(x))  // 计算绝对值

#define defaultAllTimeout 20000        // 默认蓝牙配置总超时时间
#define defaultSingleStepTimeout 1000  // 默认蓝牙配置单步超时时间

#define HC06_MasterRole "M"  // HC06主机角色
#define HC06_SlaveRole "S"   // HC06从机角色

#define BT05_TypeNoPassword "0"                 // 无密码
#define BT05_TypeSimplePairing "1"              // 简易配对
#define BT05_TypePasswordPairing "2"            // 密码配对(测试为不可用)
#define BT05_TypePasswordPairingAndBinding "3"  // 密码配对并绑定(测试为不可用)
#define BT05_MasterRole "1"                     // 主透传
#define BT05_SlaveRole "0"                      // 从透传

#define HC05_SlaveRole "0"       // HC05从机角色
#define HC05_MasterRole "1"      // HC05主机角色
#define HC05_SlaveLoopRole "2"   // HC05回环角色
#define HC05_SpecifiedCMODE "0"  // HC05指定蓝牙地址连接模式（指定蓝牙地址由绑定指令设置）
#define HC05_AnyCMODE "1"        // HC05任意蓝牙地址连接模式（不受绑定指令设置地址的约束）
#define HC05_SlaveLoopCMODE "2"  // HC05回环角色连接模式

#define JDY24M_TypeNoPassword "0"             // JDY24M连接无密码
#define JDY24M_TypeNoBindingWithPassword "1"  // JDY24M有密码连接，不绑定
#define JDY24M_TypeBindingWithPassword "2"    // JDY24M有密码连接，并绑定
#define JDY24M_Role_0 "0"                     // 从机（APP、微信、小程序）透传
#define JDY24M_Role_1 "1"                     // 主机透传模式
#define JDY24M_Role_2 "2"                     // BLE广播探针模块
#define JDY24M_Role_3 "3"                     // iBeacon模式
#define JDY24M_Role_4 "4"                     // iBeacon探针模式
#define JDY24M_Role_5 "5"                     // MESH组网模式
#define JDY24M_Role_6 "6"                     // 多连从机模式（支持4个主机连接）
#define JDY24M_Role_7 "7"                     // 多连主从机（主机支持同时连接4个从机，从机支持4个主机连接）
#define JDY24M_Role_8 "8"                     // 钥匙标签探测模式（当绑定的标签接近时，JDY-24M的IO会动作）

#define JDY18_TypeNoPassword "0"             // 不打开密码连接功能
#define JDY18_TypeNoBindingWithPassword "1"  // 打开密码连接不绑定
#define JDY18_SlaveRole "0"                  // 从机（APP、微信、小程序）透传
#define JDY18_MasterRole "1"                 // 主机透传模式
#define JDY18_SlaveiBeaconRole "3"           // 从机（iBeacon）模式

enum BluetoothConfigureState {  // 蓝牙配置状态
  ConfigureNone = 0,            // 未配置
  Configuring,                  // 正在配置
  ConfigureFailed,              // 配置失败
  ConfigureSucceeded            // 配置成功
};

class CommonFunction {
 public:
  /**
   * 函数功能：设置串口
   * 参数1：[_serial] [Stream&] 串口
   * 返回值：无
   * 注意事项：无
   */
  void setSerial(Stream& _serial);

  /**
   * 函数功能：读取串口数据
   * 参数：无
   * 返回值：[String] 读取的串口数据
   * 注意事项：会极短时间阻塞程序，每2ms接收一个字节
   */
  String getData();

  /**
   * 函数功能：读取串口数据
   * 参数1：[endChar] [char] 截止字符
   * 返回值：[String] 读取的串口数据
   * 注意事项：不会阻塞程序，需要注意的是，如果1s内没有接收到截至字符，一直等待，1s后则直接返回所接收的数据
   */
  String getData(char endChar);

  /**
   * 函数功能：发送数据
   * 参数1：[_data] [String] 发送的字符串数据
   * 参数1：[_rnState] [bool] 是否在字符串末尾添加回车换行符，true--添加，false--不添加，默认为false
   * 返回值：无
   * 注意事项：默认不带"\r\n"回车换行符
   */
  void sendData(String _data, bool _rnState = false);

  /**
   * 函数功能：设置蓝牙名称
   * 参数1：[_name] [String] 蓝牙名称
   * 返回值：无
   * 注意事项：注意蓝牙名称支持的最大字符长度
   */
  void setName(String _name);

  /**
   * 函数功能：设置蓝牙配对密码
   * 参数1：[_password] [String] 蓝牙配对密码
   * 返回值：无
   * 注意事项：注意蓝牙配对密码支持的位数
   */
  void setPassword(String _password);

  /**
   * 函数功能：设置蓝牙总配置超时时间
   * 参数1：[_timeout] [uint32_t] 超时时间
   * 返回值：无
   * 注意事项：无
   */
  void setAllConfigureTimeout(uint32_t _timeout);

  /**
   * 函数功能：设置蓝牙单步配置超时时间
   * 参数1：[_timeout] [uint32_t] 超时时间
   * 返回值：无
   * 注意事项：无
   */
  void setSingleConfigureTimeout(uint32_t _timeout);

  /**
   * 函数功能：重置蓝牙模块的波特率，主程序调用
   * 参数1：[_baudrate] [uint32_t] 串口波特率
   * 参数2：[_stopBit] [String] 停止位
   * 参数3：[_checkBit] [String] 校验位
   * 返回值：无
   * 注意事项：无
   */
  void resetBluetoothBaudrate(uint32_t _baudrate, String _stopBit = "", String _checkBit = "");

  /**
   * 函数功能：设置串口配置波特率，蓝牙类调用
   * 参数1：[_cmdStart] [String] AT前指令
   * 参数2：[_cmdEnd] [String] AT后指令（默认为空）
   * 返回值：无
   * 注意事项：无
   */
  void setSerialConfigureBaudrate(String _cmdStart, String _cmdEnd = "");

  /**
   * 函数功能：获取蓝牙配置状态
   * 参数：无
   * 返回值：配置状态，0--未配置，1--正在配置，2--配置失败，3--配置成功
   * 注意事项：无
   */
  uint8_t getConfigureState();

  /**
   * 函数功能：开始配置蓝牙
   * 参数：无
   * 返回值：无
   * 注意事项：无
   */
  void startConfigure();

  /**
   * 函数功能：检查读取数据状态
   * 参数：无
   * 返回值：false或true
   * 注意事项：无
   */
  bool checkDataState();

  /**
   * 函数功能：状态机下一步
   * 参数：无
   * 返回值：无
   * 注意事项：无
   */
  void next();

  /**
   * 函数功能：检查蓝牙配置时间
   * 参数：无
   * 返回值：无
   * 注意事项：无
   */
  void checkTime();

  /**
   * 函数功能：设置蓝牙工作模式
   * 参数1：[_role] [String] 蓝牙工作模式
   *        HC06原装版："M"--主模式Master，"S"--从模式Slave
   *        HC06兼容版："M"--主模式Master，"S"--从模式Slave
   *        BT05："0"--从透传，"1"--主透传
   * 返回值：无
   * 注意事项：无
   */
  void setRole(String _role);

  uint32_t allTimeout = defaultAllTimeout;                // 蓝牙总配置超时时间
  uint32_t singleStepTimeout = defaultSingleStepTimeout;  // 蓝牙单步配置超时时间
  uint8_t configureState = ConfigureNone;                 // 蓝牙配置状态
  uint8_t systemState = 0;                                // 系统状态机
  uint8_t lastSystemState = 0;                            // 上一次系统状态机
  uint32_t recordSystemAllTime = 0;                       // 系统当前总时间
  uint32_t recordSystemTempTime = 0;                      // 系统当前临时时间
  uint32_t serialConfigureBaudrate = 0;                   // 串口配置波特率
  String name = "";                                       // 蓝牙名称
  String password = "";                                   // 蓝牙配对密码
  String role = "";                                       // 蓝牙角色
  String type = "";                                       // 蓝牙配对类型
  String cmode = HC05_AnyCMODE;                           // 连接模式
  String bindingAddress = "";                             // 绑定蓝牙地址，仅当指定蓝牙地址连接模式时使用
  String stopBit = "";                                    // 停止位
  String checkBit = "";                                   // 校验位

 private:
  Stream* serial = NULL;  // 串口
};

#endif