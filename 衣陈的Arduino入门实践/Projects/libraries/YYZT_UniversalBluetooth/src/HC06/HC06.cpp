#include "HC06.h"

/**
 * 函数功能：配置蓝牙
 * 参数：无
 * 返回值：无
 * 注意事项：无
 */
void HC06::configureRuning() {
  switch (systemState) {
    case 0: {
      sendData("AT");
      next();
    } break;
    case 1: {
      checkTime();
    } break;
    case 2: {
      if (role != "") {
        sendData("AT+ROLE=" + role);
        next();
      } else {
        systemState = 4;
      }
    } break;
    case 3: {
      checkTime();
    } break;
    case 4: {
      if (password != "") {
        sendData("AT+PIN" + password);  // HC06兼容版蓝牙模块设置蓝牙密码后，需要重新上电蓝牙密码才会生效
        next();
      } else {
        systemState = 6;
      }
    } break;
    case 5: {
      checkTime();
    } break;
    case 6: {
      if (name != "") {
        sendData("AT+NAME" + name);  // HC06原装版（全新版）蓝牙模块设置蓝牙名称后，需要重新上电蓝牙名称才会改变
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
        setSerialConfigureBaudrate("AT+BAUD");  // HC06兼容版重新配置波特率时，如果与之前配置的波特率相同，那么不会返回串口数据
        next();
      } else {
        systemState = 10;
      }
    } break;
    case 9: {
      checkTime();
    } break;
    case 10: {
      configureState = ConfigureSucceeded;
    } break;
  }
}
