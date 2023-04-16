#include "BT05_AT09.h"

/**
 * 函数功能：配置蓝牙
 * 参数：无
 * 返回值：无
 * 注意事项：无
 */
void BT05_AT09::configureRuning() {
  switch (systemState) {
    case 0: {
      sendData("AT\r\n");
      next();
    } break;
    case 1: {
      checkTime();
    } break;
    case 2: {
      if (type != "") {
        sendData("AT+TYPE" + type + "\r\n");
        next();
      } else {
        systemState = 4;
      }
    } break;
    case 3: {
      checkTime();
    } break;
    case 4: {
      if (name != "") {
        sendData("AT+NAME" + name + "\r\n");
        next();
      } else {
        systemState = 6;
      }
    } break;
    case 5: {
      checkTime();
    } break;
    case 6: {
      if (type == BT05_TypeNoPassword || password == "") {
        systemState = 8;
      } else {
        sendData("AT+PIN" + password + "\r\n");
        next();
      }
    } break;
    case 7: {
      checkTime();
    } break;
    case 8: {
      if (role != "") {
        sendData("AT+ROLE" + role + "\r\n");
        next();
      } else {
        systemState = 10;
      }
    } break;
    case 9: {
      checkTime();
    } break;
    case 10: {
      sendData("AT+RESET\r\n");
      next();
    } break;
    case 11: {
      checkTime();
    } break;
    case 12: {
      sendData("AT\r\n");
      next();
    } break;
    case 13: {
      checkTime();
    } break;
    case 14: {
      if (serialConfigureBaudrate != 0) {
        setSerialConfigureBaudrate("AT+BAUD", "\r\n");
        next();
      } else {
        systemState = 16;
      }
    } break;
    case 15: {
      checkTime();
    } break;
    case 16: {
      configureState = ConfigureSucceeded;
    } break;
  }
}

/**
 * 函数功能：设置蓝牙模块鉴权工作类型
 * 参数1：[_type] [String] 蓝牙模块鉴权工作类型
 *        BT05："0"--无密码，"1"--简易配对，"2"--密码配对，"3"--密码配对并绑定
 * 返回值：无
 * 注意事项：无
 */
void BT05_AT09::setType(String _type) {
  type = _type;
}
