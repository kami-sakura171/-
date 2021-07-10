### 1.命令行窗口 help 函数名

了解函数用法

### 2.subplot函数

用法：subplot(m,n,p); 或 subplot(m n p);

subplot是将多个图画到一个平面上的工具。其中，m表示是图排成m行，n表示图排成n列，也就是整个figure中有n个图是排成一行的，一共m行，如果m=2就是表示2行图。p表示图所在的位置，p=1表示从左到右从上到下的第一个位置。

### 3.edge函数

通常用于提取边缘或边缘检测。

edge - 查找强度图像的边缘
    此 MATLAB 函数 返回二值图像 BW，其中的值 1 对应于灰度或二值图像 I 中函数找到边缘的位
    置，值 0 对应于其他位置。默认情况下，edge 使用 Sobel 边缘检测方法。

```matlab
BW = edge(I)
BW = edge(I,method)
BW = edge(I,method,threshold)
BW = edge(I,method,threshold,direction)
BW = edge(___,'nothinning')
BW = edge(I,method,threshold,sigma)
BW = edge(I,method,threshold,h)

[BW,threshOut] = edge(___)
[BW,threshOut,Gv,Gh] = edge(___)
```

###  4.wiener2

​	二维自适应去噪滤波
​    此 MATLAB 函数 使用像素级自适应低通 Wiener 滤波器对灰度图像 I 进行滤波。[m n] 指定
​    用于估计局部图像均值和标准差的邻域的大小（m×n）。加性噪声（高斯白噪声）功率假定为
noise。

```matlab
J = wiener2(I,[m n],noise)
[J,noise_out] = wiener2(I,[m n])
```

