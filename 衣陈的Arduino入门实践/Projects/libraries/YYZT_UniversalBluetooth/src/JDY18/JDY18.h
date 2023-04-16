#ifndef JDY18_H
#define JDY18_H

#include "./CommonFunction/CommonFunction.h"

class JDY18 : public CommonFunction {
 public:
  /**
   * 函数功能：配置蓝牙
   * 参数：无
   * 返回值：无
   * 注意事项：无
   */
  void configureRuning();

  /**
   * 函数功能：设置密码密码连接开关
   * 参数1：[_type] [String] 密码连接开关
   *        JDY18_TypeNoPassword--不打开密码连接功能
   *        JDY18_TypeNoBindingWithPassword--打开密码连接不绑定
   * 返回值：无
   * 注意事项：无
   */
  void setType(String _type);
};

#endif