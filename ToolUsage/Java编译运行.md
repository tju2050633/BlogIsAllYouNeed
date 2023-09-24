## Java编译运行



### 一、javac、java命令



### 测试目录结构

```
// 项目根目录

.
├── bin
│   ├── test1	# 包test1里的class文件
│   ├── test2	# 包test2里的class文件
│   └── Main.class
└── src
    ├── test1
    │   └── hello.java
    ├── test2
    │   └── hi.java
    └── Main.java

```

- `bin`目录是`javac`命令产生的所有class文件（目录结构和src里一模一样）
- `src`放所有源码
  - 每个子目录代表一个包，包名必须和子目录名一致
    - 声明包：package <name>;
    - 导入包：import <p1>.<p2>.<类名>（或*）
  - .java文件名必须和public 类名一致



### 构建运行

终端处于项目根目录。

```sh
javac -d bin -cp src src/Main.java && java -cp bin Main
```

- `javac -d bin -cp src src/Main.java`编译
  - -d bin指定class文件输出目录
  - -cp src指定classpath，这里是源文件所在目录
  - src/Main.java指定入口文件路径

- java -cp bin Main
  - -cp src指定classpath，这里是class文件所在位置
  - Main是入口类名





### 二、maven

- 设置JAVA_HOME环境变量，目前使用export命令，参考《Java版本控制.md》
- 编译：根目录下`mvn clean package`
- 运行：java -jar target/<jar-file-name>.jar
- 自动修改后编译运行：mvn spring-boot:run



Created On : 2023-09-22
Last Modified : 2023-09-24