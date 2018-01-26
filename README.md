# UAV_code_practice_cpp

这是 UAV 目标跟踪项目的 C++ 原型代码和练习程序仓库
由：胡震宇，季存远，吴昊共同维护

## 命令行编译
cvl.cmd 是MSVC 命令行编译脚本
``` batch
cl /EHsc /I <OPENCV_INCLUDE_PATH> <OPENCV_LIBS_PATH>
```
请按照需求修改, 且使用您的 MSVC x64 Native Tools 编译

## ROI定义
一个无聊的练习。OpenCV 定义兴趣区域

## 视频方法
VideoAPI.cpp

基础的视频操作方法，类定义接口在 utils.hpp。当前尚未移除cpp文件中的接口定义。一俟开发完成，该文件中应当只有视频方法，与类定义分开，

## 通用接口
utils.hpp
通用接口头文件，请在其中定义您需要的类，改在cpp文件中再定义对应方法
