#ifndef JDY24M_H
#define JDY24M_H

#include "./CommonFunction/CommonFunction.h"

class JDY24M : public CommonFunction {
 public:
  /**
   * 函数功能：配置蓝牙
   * 参数：无
   * 返回值：无
   * 注意事项：无
   */
  void configureRuning();

  /**
   * 函数功能：设置蓝牙密码连接方式
   * 参数1：[_type] [String] 蓝牙密码连接方式
   *        JDY24M_TypeNoPassword--连接无密码
   *        JDY24M_TypeNoBindingWithPassword--有密码连接，不绑定
   *        JDY24M_TypeBindingWithPassword--JDY24M有密码连接，并绑定
   * 返回值：无
   * 注意事项：无
   */
  void setType(String _type);
};

#endif
