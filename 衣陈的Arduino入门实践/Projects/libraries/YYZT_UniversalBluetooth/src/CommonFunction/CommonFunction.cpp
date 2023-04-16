#include "CommonFunction.h"

/**
 * 函数功能：设置串口
 * 参数1：[_serial] [Stream&] 串口
 * 返回值：无
 * 注意事项：无
 */
void CommonFunction::setSerial(Stream& _serial) {
  serial = &_serial;
}

/**
 * 函数功能：读取串口数据
 * 参数：无
 * 返回值：[String] 读取的串口数据
 * 注意事项：会极短时间阻塞程序，每2ms接收一个字节
 */
String CommonFunction::getData() {
  String readData = "";

  while (serial->available() > 0) {
    readData += (char)(serial->read());
    delay(2);
  }

  return readData;
}

/**
 * 函数功能：读取串口数据
 * 参数1：[endChar] [char] 截止字符
 * 返回值：[String] 读取的串口数据
 * 注意事项：不会阻塞程序，需要注意的是，如果1s内没有接收到截至字符，一直等待，1s后则直接返回所接收的数据
 */
String CommonFunction::getData(char endChar) {
  String readData = "";

  if (serial->available() > 0) {
    readData = serial->readStringUntil(endChar);
  }

  return readData;
}

/**
 * 函数功能：发送数据
 * 参数1：[_data] [String] 发送的字符串数据
 * 参数1：[_rnState] [bool] 是否在字符串末尾添加回车换行符，true--添加，false--不添加，默认为false
 * 返回值：无
 * 注意事项：默认不带"\r\n"回车换行符
 */
void CommonFunction::sendData(String _data, bool _rnState) {
  if (_rnState) {
    serial->println(_data);
    return;
  }
  serial->print(_data);
}

/**
 * 函数功能：设置蓝牙名称
 * 参数1：[_name] [String] 蓝牙名称
 * 返回值：无
 * 注意事项：注意蓝牙名称支持的最大字符长度
 */
void CommonFunction::setName(String _name) {
  name = _name;
}

/**
 * 函数功能：设置蓝牙配对密码
 * 参数1：[_password] [String] 蓝牙配对密码
 * 返回值：无
 * 注意事项：注意蓝牙配对密码支持的位数
 */
void CommonFunction::setPassword(String _password) {
  password = _password;
}

/**
 * 函数功能：设置蓝牙总配置超时时间
 * 参数1：[_timeout] [uint32_t] 超时时间
 * 返回值：无
 * 注意事项：无
 */
void CommonFunction::setAllConfigureTimeout(uint32_t _timeout) {
  allTimeout = _timeout;
}

/**
 * 函数功能：设置蓝牙单步配置超时时间
 * 参数1：[_timeout] [uint32_t] 超时时间
 * 返回值：无
 * 注意事项：无
 */
void CommonFunction::setSingleConfigureTimeout(uint32_t _timeout) {
  singleStepTimeout = _timeout;
}

/**
 * 函数功能：重置蓝牙模块的波特率，主程序调用
 * 参数1：[_baudrate] [uint32_t] 串口波特率
 * 参数2：[_stopBit] [String] 停止位
 * 参数3：[_checkBit] [String] 校验位
 * 返回值：无
 * 注意事项：无
 */
void CommonFunction::resetBluetoothBaudrate(uint32_t _baudrate, String _stopBit, String _checkBit) {
  serialConfigureBaudrate = _baudrate;
  stopBit = _stopBit;
  checkBit = _checkBit;
}

/**
 * 函数功能：设置串口配置波特率，蓝牙类调用
 * 参数1：[_cmdStart] [String] AT前指令
 * 参数2：[_cmdEnd] [String] AT后指令（默认为空）
 * 返回值：无
 * 注意事项：无
 */
void CommonFunction::setSerialConfigureBaudrate(String _cmdStart, String _cmdEnd) {
  uint32_t tempBaudrate[12] = {
      1200, 2400, 4800, 9600, 19200, 38400, 57600,
      115200, 230400, 460800, 921600, 1382400};
  String data[12] = {
      "1", "2", "3", "4", "5", "6",
      "7", "8", "9", "A", "B", "C"};

  for (uint8_t i = 0; i < 12; i++) {
    if (tempBaudrate[i] == serialConfigureBaudrate) {
      sendData(_cmdStart + data[i] + _cmdEnd);
      return;
    }
  }
}

/**
 * 函数功能：获取蓝牙配置状态
 * 参数：无
 * 返回值：配置状态，0--未配置，1--正在配置，2--配置失败，3--配置成功
 * 注意事项：无
 */
uint8_t CommonFunction::getConfigureState() {
  return configureState;
}

/**
 * 函数功能：开始配置蓝牙
 * 参数：无
 * 返回值：无
 * 注意事项：无
 */
void CommonFunction::startConfigure() {
  systemState = 0;
  configureState = Configuring;
  recordSystemAllTime = millis();
}

/**
 * 函数功能：检查读取数据状态
 * 参数：无
 * 返回值：false或true
 * 注意事项：无
 */
bool CommonFunction::checkDataState() {
  String readData = getData();
  readData.trim();
  if (readData.indexOf("OK") != -1 || readData.indexOf("Ok") != -1 || readData.indexOf("=") != -1 || readData.indexOf("+") != -1) {
    // Serial.println(readData);
    return true;
  }
  return false;
}

/**
 * 函数功能：状态机下一步
 * 参数：无
 * 返回值：无
 * 注意事项：无
 */
void CommonFunction::next() {
  lastSystemState = systemState;
  systemState++;
  recordSystemTempTime = millis();
}

/**
 * 函数功能：检查蓝牙配置时间
 * 参数：无
 * 返回值：无
 * 注意事项：无
 */
void CommonFunction::checkTime() {
  if (YYZT_abs(millis() - recordSystemAllTime) >= allTimeout) {
    configureState = ConfigureFailed;
    return;
  }

  if (YYZT_abs(millis() - recordSystemTempTime) <= singleStepTimeout) {
    if (checkDataState()) {
      systemState++;
      // Serial.println(systemState);
      return;
    }
  } else {
    systemState = lastSystemState;
  }
}

/**
 * 函数功能：设置蓝牙工作模式
 * 参数1：[_role] [String] 蓝牙工作模式
 *        HC06原装版："M"--主模式Master，"S"--从模式Slave
 *        HC06兼容版："M"--主模式Master，"S"--从模式Slave
 *        BT05："0"--从透传，"1"--主透传
 * 返回值：无
 * 注意事项：无
 */
void CommonFunction::setRole(String _role) {
  role = _role;
}
