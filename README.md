# UAV_code_practice_cpp

这是 UAV 目标跟踪项目的 C++ 原型代码和练习程序仓库，由：胡震宇，季存远，吴昊共同维护

系统方案请见 uav_flowchart.jpg 流程图文件

需要注意的是，obj 和exe 文件八成不能在您的机器上运行，它们对您没有什么卵用，请您无视它们吧。
## 通用接口
utils.hpp

通用接口头文件，请在其中定义您需要的类，转到cpp文件中再定义对应方法


## 命令行编译
cvl.cmd 是MSVC 命令行编译脚本

``` batch
cl /EHsc /I <OPENCV_INCLUDE_PATH> <OPENCV_LIBS_PATH> %1.cpp
```

cplall.cmd 是联编整个项目的cpp源文件用的

``` batch
del *.obj *.exe
cl /EHsc /I H:\opencv\build\include H:\opencv\build\x64\vc14\lib\*.lib ./*.cpp /Fetest
```

请按照需求修改包含和库目录, 且使用您的 MSVC x64 Native Tools 编译

## ROI定义
一个无聊的练习，OpenCV 定义兴趣区域

## 视频方法
VideoAPI.cpp

基础的视频操作方法，类接口在 utils.hpp。尚在开发中。

应当包含：

    1. 从文件读取视频并显示（按帧）
    2. 从摄像头读取并显示 （按帧）
    3. 读取图片序列并按一定帧率显示
    4. 能够插入逐帧操作
    5. 能够插入帧间操作（时空立方体提取和缓存）
    6. 写视频 （从逐帧视频写文件或者从图形序列写文件）

以上实现的有: [1, 2, 4]

当前尚未移除cpp文件中的接口定义, 便于测试方法的正确性。

一俟开发完成，该文件中应当只有视频方法，与头文件类接口分开。main函数的entry将被移除。


