#ifndef HC06_H
#define HC06_H

#include "./CommonFunction/CommonFunction.h"

class HC06 : public CommonFunction {
 public:
  /**
   * 函数功能：配置蓝牙
   * 参数：无
   * 返回值：无
   * 注意事项：无
   */
  void configureRuning();
};

#endif