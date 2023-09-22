## CMake构建C++项目（VSCode，gcc）

### 测试目录结构

```
// 项目根目录

.
├── bin
├ ...(CMakeFiles、静态链接库、Makefile、Cache、exec等。省略)
└── src
    ├── CMakeLists.txt
    ├── func.cpp
    ├── func.h
    ├── main.cpp
    └── test
        ├── CMakeLists.txt
        ├── test.cpp
        └── test.h
```

- `bin`目录是make产生的文件，以及最后的可执行文件
- `src`放所有源码
  - `src`下的`CMakeLists.txt`用来构建项目
  - `func.h`和`func.cpp`测试根目录下链接文件
  - `main.cpp`入口函数
  - `test`子目录放静态链接库代码，测试子目录下链接文件
    - `test`下的`CMakeLists.txt`用来构建静态链接库
    - `test.h`和`test.cpp`测试子目录下（静态链接库）链接文件



### 构建运行

先cd进bin目录。

```sh
cmake ../src && make && ./Demo
```

- `cmake ../src`在src目录下进行cmake（查找源文件），并在当前目录下（bin）生成CMakeFiles等
- `make`用当前目录下（bin）的Makefile构建
- `./Demo`运行当前目录下（bin）的可执行文件，文件名同根目录的`CMakeLists.txt`中指定的项目名



### CMakeLists.txt内容

**根目录下的**

```cmake
# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (Demo)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
# 这里找到func.cpp
# 若只有一个main.cpp，可以不用这行
aux_source_directory(. DIR_SRCS)

# 添加 test 子目录
# 寻找动态链接库
add_subdirectory(test)

# 指定生成目标
# 若只有一个main.cpp，可以add_executable(Demo main.cpp)
add_executable(Demo ${DIR_SRCS})

# 添加链接库
target_link_libraries(Demo Test)
```

**子目录下的**

```cmake
# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(. DIR_LIB_SRCS)

# 生成链接库
add_library (Test ${DIR_LIB_SRCS})
```



### 包含eigen等库的问题

包含eigen/opencv库还是有问题，CMake找不到库路径，g++命令可以用eigen但找不到opencv。待解决



Created On : 2023-09-22
Last Modified : 2023-09-22