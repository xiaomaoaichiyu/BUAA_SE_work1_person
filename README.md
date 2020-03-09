# Run instruction:

程序仅支持文件输出，同时把输出打印到-o [file name]指定的文件中；

**具体使用的命令如下**：

```shell
intersect.exe -i “input file name” -o "output file name"
```

若输出的参数不符合格式或者缺失将返回错误信息。



输入：

- 首行代表有多少个几何图形

- 支持直线和圆
  - 直线输入格式：L x1, y1, x2, y2
  - 圆输入格式：C x y r



输出：

- 所有几何图形的交点数，行末没有换行符。

