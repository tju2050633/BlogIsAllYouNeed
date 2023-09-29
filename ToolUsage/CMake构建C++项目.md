## CMake构建C++项目（VSCode，gcc）



> Demo项目src在同一目录下cmake_src



### 测试目录结构

```
// 项目根目录

.
├── bin
├ ...(CMakeFiles、静态链接库、Makefile、Cache、exec等。省略)
├── data
│   └── test.png
└── src
    ├── CMakeLists.txt
    ├── func.cpp
    ├── func.h
    ├── main.cpp
    ├── test
    │   ├── test.cpp
    │   └── test.h
    └── test1
        ├── test1.cpp
        ├── test1.h
        └── test2
            ├── test2.cpp
            └── test2.h
```

- `bin`目录是make产生的文件，以及最后的可执行文件
- `src`放所有源码
  - `src`下的`CMakeLists.txt`用来构建项目
  - `func.h`和`func.cpp`测试根目录下链接文件
  - `main.cpp`入口函数
  - `test`子目录放静态链接库代码，测试子目录下链接文件
  - `test1`和`test1/test2`子目录放静态链接库代码，测试多重子目录下链接文件



### 构建运行

先cd进bin目录。

```sh
cmake ../src && make && ./Demo
```

- `cmake ../src`在src目录下进行cmake（查找源文件），并在当前目录下（bin）生成CMakeFiles等
- `make`用当前目录下（bin）的Makefile构建
- `./Demo`运行当前目录下（bin）的可执行文件，文件名同根目录的`CMakeLists.txt`中指定的项目名

### main.cpp中的include语句

```c++
#include <iostream>
#include "func.h"
#include "test/test.h"
#include "test1/test1.h"
#include "test1/test2/test2.h"

// 注意这两个库的路径，都是从其include目录开始的
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>
#include <opencv2/opencv.hpp>
```





### CMakeLists.txt内容

```cmake
### config

cmake_minimum_required (VERSION 2.8) # CMake最低版本要求
project (Demo)	# 项目名称（涉及到后面的可执行文件名、链接）

### compile

aux_source_directory(. DIR_SRCS) # 根目录代码
add_executable(Demo ${DIR_SRCS}) # 生成可执行文件

### static link library
## 本地编译出来的静态链接库都可以通过以下方式加入构建
## 1. 获取子目录下所有源代码
## 2. 添加静态链接库，指定名称、STATIC、源代码
## 3. 链接到可执行文件上

# test
aux_source_directory(test DIR_TEST_SRCS)
add_library(test STATIC ${DIR_TEST_SRCS})
target_link_libraries(Demo test)

# test1
aux_source_directory(test1 DIR_TEST1_SRCS)
add_library(test1 STATIC ${DIR_TEST1_SRCS})
target_link_libraries(Demo test1)

# test1/test2
aux_source_directory(test1/test2 DIR_TEST2_SRCS)
add_library(test2 STATIC ${DIR_TEST2_SRCS})
target_link_libraries(Demo test2)

## eigen和opencv等外部库下面细说

# eigen
include_directories(/usr/local/Cellar/eigen/3.4.0_1/include)
add_library(eigen INTERFACE)
target_include_directories(eigen INTERFACE /usr/local/Cellar/eigen/3.4.0_1/include)
target_link_libraries(Demo eigen)

# opencv
include_directories(/usr/local/Cellar/opencv@3/3.4.16_10/include)
file(GLOB OpenCV_LIBS /usr/local/Cellar/opencv@3/3.4.16_10/lib/*.dylib)
target_link_libraries(Demo ${OpenCV_LIBS})

```

### 包含eigen/opencv等库

1. 添加include路径，这是为了#include这行代码，应到找到库的路径并指定其**include**目录路径
2. 对于eigen，只包含头文件，实现通过模板在编译期展开，不需要预编译的库，因此使用INTERFACE库只指定include目录，不需要链接文件
3. 对于opencv，包含头文件和库文件，需要指定include目录和opencv库文件路径来链接
4. 链接到可执行文件上



Created On : 2023-09-22
Last Modified : 2023-09-29