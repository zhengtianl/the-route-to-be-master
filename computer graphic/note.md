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


  git push