#ifndef BT05_AT09_H
#define BT05_AT09_H

#include "./CommonFunction/CommonFunction.h"

class BT05_AT09 : public CommonFunction {
 public:
  /**
   * 函数功能：配置蓝牙
   * 参数：无
   * 返回值：无
   * 注意事项：无
   */
  void configureRuning();

  /**
   * 函数功能：设置蓝牙模块鉴权工作类型
   * 参数1：[_type] [String] 蓝牙模块鉴权工作类型
   *        BT05："0"--无密码，"1"--简易配对，"2"--密码配对，"3"--密码配对并绑定
   * 返回值：无
   * 注意事项：无
   */
  void setType(String _type);
};

#endif
