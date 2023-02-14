# Raster（光栅化）
Raster (or bitmap) images are generally what you think about when thinking of images. These are the types of images that are produced when scanning or photographing an object. Raster images are compiled using pixels, or tiny dots, containing unique color and tonal information that come together to create the image
光只能通过相同的震动方向

通过采样放来做光栅化，把函数离散化

```c++
for(int x =0; x < xmax；x++)
    for (int  y = 0;y <maxy; y++)
        image[x][y] = inside(triangle,
                             x+0.5,
                             y+0.5);
inside(triangle,x,y);
````

如果在三角形边界上不做处理或者特殊处理

光栅化赋值方法：
bounding box
总之每个可能的像素是否在三角形内，图形由三角形组成

三原色：
红绿蓝
Jaggies
抗锯齿反走样

# why triangles

**Most basic polygon**
* break up other polygon

**unique properties**
* guaranteed to be planer
* well-defined interior
* well-defined method for interpolating values at
* vertices over triangles(barycentric interpolation)

CPU与GPU的通信方式
* CPU和GPU是一种CS模式，即客户端-服务器模式。
* 客户端不能直接访问服务器资源，客户端想对服务器资源进行操作，只能通过网络协议交互，由服务器进行操作。
* CPU就是客户端，GPU就是服务器。
  
* _步骤	OpenGL API	描述
  1	glGenTextures	通知显卡创建纹理对象，返回句柄;
  2	glBindTexture	将纹理绑定到特定纹理目标;
  3	glTexImage2D	将图片rgb数据上传到GPU;
  需要注意的是，上面的API都是阻塞式的。
  所以在游戏中，需要减小图片尺寸减少上传时间，需要打包图集减少上传次数。_


heightfield:(等高线)
level of detail 可以动态更新object的details
mesh tessellation
triangle-based subdivision(二叉树结构)
T-junctions 问题：

现在用的最多 QuadTree-Based Subdivison (四叉树)

hull shader
domain shader
geogragh shader

mesh shader  Mesh shader
Mesh shaders is a new geometry pipeline that replaces the vertex shader stage with two new programmable stages-- the object shader stage and the mesh shader stage. In this example, the object shader would take geometry as an input , process it and output some data-- which we call "payload"-- to the mesh shader. 
网格着色器管道提供了许多好处： 通过着色器单元提高可扩展性，减少基元处理中的固定功能影响。现代 GPU 的通用用途有助于更多种类的应用程序添加更多内核并提高着色器的通用内存和算术性能

Crazy Idea - Volumetric Representation
marching Cubes

displacement mapping
采样8个点需要7个插值 两个mip level， mipmap


directStorage & DMA
往GPU写数据

浮点精度问题导致屏幕抖动

Camer-Relative Rendering 重置世界坐标系

Decorator 

Road and Decals Rendering

# 天空模型
Analytic Atmosphere Appearance Modeling

# 渲染pipeline
1. vertex shader 
2. shape Assembly 
3. Geometry Shader
4. test and blending
5. FRAGMENT shader
6. RASTERIZATION

