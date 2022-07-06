# VeighNa框架的恒生NSQ极速行情接口

<p align="center">
  <img src ="https://vnpy.oss-cn-shanghai.aliyuncs.com/vnpy-logo.png"/>
</p>

<p align="center">
    <img src ="https://img.shields.io/badge/version-1.0.0-blueviolet.svg"/>
    <img src ="https://img.shields.io/badge/platform-windows-yellow.svg"/>
    <img src ="https://img.shields.io/badge/python-3.7|3.8|3.9|3.10-blue.svg" />
    <img src ="https://img.shields.io/github/license/vnpy/vnpy.svg?color=orange"/>
</p>

## 说明

基于恒生NSQ极速行情API开发的行情接口。


## 连接

连接前请先将sdk_config.ini放置在VN Trader运行目录（.vntrader同级文件夹）下。

请注意：

1. 如果需要关闭sdk在终端的日志输出，可以将ini文件中的console_output_log的参数改为0。

2. ini文件中所有【接收组播行情的本机网卡IP】参数需要修改成本机地址。

### 常见问题

#### Windows - 数据丢包

若通过Windows连接，出现丢包问题，可以参考nsq的API文档中3.3【运行配置（windows）】部分内容，配置组播接收绕过BFE解决。
