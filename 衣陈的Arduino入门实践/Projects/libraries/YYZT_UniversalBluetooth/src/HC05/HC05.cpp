#include "HC05.h"

/**
 * 函数功能：配置蓝牙
 * 参数：无
 * 返回值：无
 * 注意事项：无
 */
void HC05::configureRuning() {
  switch (systemState) {
    case 0: {
      if (name != "") {
        sendData("AT+NAME=" + name + "\r\n");
        next();
      } else {
        systemState = 2;
      }
    } break;
    case 1: {
      checkTime();
    } break;
    case 2: {
      if (password != "") {
        sendData("AT+PSWD=" + password + "\r\n");
        next();
      } else {
        systemState = 4;
      }
    } break;
    case 3: {
      checkTime();
    } break;
    case 4: {
      if (role != "") {
        sendData("AT+ROLE=" + role + "\r\n");
        next();
      } else {
        systemState = 6;
      }
    } break;
    case 5: {
      checkTime();
    } break;
    case 6: {
      if (cmode != "") {
        sendData("AT+CMODE=" + cmode + "\r\n");
        next();
      } else {
        systemState = 8;
      }
    } break;
    case 7: {
      checkTime();
    } break;
    case 8: {
      if (serialConfigureBaudrate != 0) {
        sendData("AT+UART=" + String(serialConfigureBaudrate) + "," + stopBit + "," + checkBit + "\r\n");
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
      configureState = ConfigureSucceeded;
    } break;
  }
}

/**
 * 函数功能：设置连接模式
 * 参数1：[_cmode] [String] 连接模式
 *        HC05_OriginalVersionSpecifiedCMODE——指定蓝牙地址连接模式（指定蓝牙地址由绑定指令设置）
 *        HC05_OriginalVersionAnyCMODE——任意蓝牙地址连接模式（不受绑定指令设置地址的约束）
 *        HC05_OriginalVersionSlaveLoopCMODE——回环角色（Slave-Loop）
 * 参数2：[_bindingAddress] [String] 绑定蓝牙地址，仅当指定蓝牙地址连接模式时使用
 * 返回值：无
 * 注意事项：无
 */
void HC05::setCMODE(String _cmode, String _bindingAddress) {
  cmode = _cmode;
  bindingAddress = _bindingAddress;
}
