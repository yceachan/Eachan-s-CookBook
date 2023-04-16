#include "JDY31.h"

/**
 * 函数功能：配置蓝牙
 * 参数：无
 * 返回值：无
 * 注意事项：无
 */
void JDY31::configureRuning() {
  switch (systemState) {
    case 0: {
      if (name != "") {
        sendData("AT+NAME" + name + "\r\n");
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
        sendData("AT+PIN" + password + "\r\n");
        next();
      } else {
        systemState = 4;
      }
    } break;
    case 3: {
      checkTime();
    } break;
    case 4: {
      if (serialConfigureBaudrate != 0) {
        setSerialConfigureBaudrate("AT+BAUD", "\r\n");  // 重新设置波特率后重新上电才会生效
        next();
      } else {
        systemState = 6;
      }
    } break;
    case 5: {
      checkTime();
    } break;
    case 6: {
      sendData("AT+RESET\r\n");
      next();
    } break;
    case 7: {
      checkTime();
    } break;
    case 8: {
      if (getData() == "") {  // 配置成功后可能会有一个乱码数据，等待2000ms把它读掉
        if (YYZT_abs(millis() - recordSystemTempTime) >= 2000) {
          configureState = ConfigureSucceeded;
        }
      } else {
        configureState = ConfigureSucceeded;
      }
    } break;
  }
}
