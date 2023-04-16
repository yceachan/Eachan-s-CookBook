#include "HC02.h"

/**
 * 函数功能：配置蓝牙
 * 参数：无
 * 返回值：无
 * 注意事项：无
 */
void HC02::configureRuning() {
  switch (systemState) {
    case 0: {
      sendData("AT");
      next();
    } break;
    case 1: {
      checkTime();
    } break;
    case 2: {
      if (password != "") {
        sendData("AT+PIN" + password);
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
        sendData("AT+NAME" + name);
        next();
      } else {
        systemState = 6;
      }
    } break;
    case 5: {
      checkTime();
    } break;
    case 6: {
      sendData("AT+RESET");
      next();
    } break;
    case 7: {
      checkTime();
    } break;
    case 8: {
      if (serialConfigureBaudrate != 0) {
        setSerialConfigureBaudrate("AT+BAUD");
        next();
      } else {
        systemState = 10;
      }
    } break;
    case 9: {
      checkTime();
    } break;
    case 10: {
      next();
    } break;
    case 11: {
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
