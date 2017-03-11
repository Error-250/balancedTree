# balancedTree
balanced Tree
## 文件结构
```
+
|
 --main.c 主程序
|
 --trre.c 二叉树
|
 --tree.h 二叉树结构体及函数的声明
|
 --adjusttree.h 调整树的函数声明
|
 --adjusttree.c 调整二叉树
|
 --Makefile 一键编译
|
 --util+
    |
     --queue.h 队列结构体及函数声明
    |
     --queue.c 队列
```

### 简介
著名的平衡树算法有AVL, 红黑树等, 然而他们是在已经存在一棵树的情况下进行调整。
本平衡树与此不同, 它是在创建的时候就不断调整为平衡树.

### 运行截图
!()[https://github.com/Error-250/balancedTree/blob/master/result.PNG]

### 编译
```
make all
```
