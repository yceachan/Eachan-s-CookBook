#ifndef HC05_H
#define HC05_H

#include "./CommonFunction/CommonFunction.h"

class HC05 : public CommonFunction {
 public:
  /**
   * 函数功能：配置蓝牙
   * 参数：无
   * 返回值：无
   * 注意事项：无
   */
  void configureRuning();

  /**
   * 函数功能：设置连接模式
   * 参数1：[_cmode] [String] 连接模式
   *        0——指定蓝牙地址连接模式（指定蓝牙地址由绑定指令设置）
   *        1——任意蓝牙地址连接模式（不受绑定指令设置地址的约束）
   *        2——回环角色（Slave-Loop）
   * 参数2：[_bindingAddress] [String] 绑定蓝牙地址，仅当指定蓝牙地址连接模式时使用
   * 返回值：无
   * 注意事项：无
   */
  void setCMODE(String _cmode, String _bindingAddress = "");
};

#endif
