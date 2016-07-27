# Soft-pipeline

软渲染管线，主要通过软件代码实现DirectX中固定管线的功能。

个人作品，计算机图形学基础项目。

程序简要说明
===

* 采用D3D标准坐标系（左手坐标系）
* 标准固定管线，三次矩阵变换（WORLD/VIEW/PROJECTION），四次坐标变换。
* 线框渲染，Bresenham画线。
* 双缓冲渲染。

演示
===

线框渲染，正面效果。
![](https://raw.githubusercontent.com/moonightlei/Soft-pipeline/master/images/image_1.jpg)

线框渲染，x，y，z轴各旋转45度效果。
![](https://raw.githubusercontent.com/moonightlei/Soft-pipeline/master/images/image_2.jpg)


计划中待完善的功能/bug
=======
* 坐标转换中出现的顶点z与w值不正确的bug。
* 简单CVV裁剪。
* 支持纹理贴图。
* 颜色渲染。
* 深度缓存。

参考资料
======
SkyWind3000的mini3d项目：https://github.com/skywind3000/mini3d
从零实现3D引擎：http://blog.csdn.net/cppyin/article/category/780767
