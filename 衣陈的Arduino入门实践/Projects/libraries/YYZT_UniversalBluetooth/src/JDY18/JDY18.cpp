#include "JDY18.h"

/**
 * 函数功能：配置蓝牙
 * 参数：无
 * 返回值：无
 * 注意事项：无
 */
void JDY18::configureRuning() {
  switch (systemState) {
    case 0: {
      if (type != "") {
        sendData("AT+TYPE" + type + "\r\n");
        next();
      } else {
        systemState = 2;
      }
    } break;
    case 1: {
      checkTime();
    } break;
    case 2: {
      if (name != "") {
        sendData("AT+NAME" + name + "\r\n");
        next();
      } else {
        systemState = 4;
      }
    } break;
    case 3: {
      checkTime();
    } break;
    case 4: {
      if (type == JDY18_TypeNoPassword || password == "") {
        systemState = 6;
      } else {
        sendData("AT+PIN" + password + "\r\n");
        next();
      }
    } break;
    case 5: {
      checkTime();
    } break;
    case 6: {
      if (role != "") {
        sendData("AT+ROLE" + role + "\r\n");
        next();
      } else {
        systemState = 8;
      }
    } break;
    case 7: {
      checkTime();
    } break;
    case 8: {
      sendData("AT+RESET\r\n");
      next();
    } break;
    case 9: {
      checkTime();
    } break;
    case 10: {
      if (serialConfigureBaudrate != 0) {
        setSerialConfigureBaudrate("AT+BAUD", "\r\n");
        next();
      } else {
        systemState = 12;
      }
    } break;
    case 11: {
      checkTime();
    } break;
    case 12: {
      configureState = ConfigureSucceeded;
    } break;
  }
}

/**
 * 函数功能：设置密码密码连接开关
 * 参数1：[_type] [String] 密码连接开关
 *        JDY18_TypeNoPassword--不打开密码连接功能
 *        JDY18_TypeNoBindingWithPassword--打开密码连接不绑定
 * 返回值：无
 * 注意事项：无
 */
void JDY18::setType(String _type) {
  type = _type;
}
