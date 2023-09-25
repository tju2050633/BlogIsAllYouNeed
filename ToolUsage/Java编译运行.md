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

- maven初始化项目：在项目根目录下`mvn archetype:generate -DgroupId=com.mycompany.app -DartifactId=my-app -DarchetypeArtifactId=maven-archetype-quickstart -DarchetypeVersion=1.4 -DinteractiveMode=false`

> 解释:
>
> - `archetype:generate` 表示使用Maven Archetype插件生成项目
> - `-DgroupId` 指定项目的组Id为com.mycompany.app
> - `-DartifactId` 指定项目的artifactId为my-app
> - `-DarchetypeArtifactId` 指定使用maven-archetype-quickstart archetype
> - `-DarchetypeVersion` 指定archetype的版本为1.4
> - `-DinteractiveMode=false` 表示不用交互式配置
>
> 1. 进入生成的my-app目录,会看到一个最小的Maven项目结构,包含src、pom.xml等文件
> 2. 在my-app目录下运行:`mvn package` 可以编译项目
> 3. `java -cp target/my-app-1.0-SNAPSHOT.jar com.mycompany.app.App` 可以运行项目
> 4. 现在就可以开始在src/main/java下开发Java代码,并使用Maven进行编译和运行了

- 后端大项目：

  - 设置JAVA_HOME环境变量，目前使用export命令，参考《Java版本控制.md》

  - 编译：根目录下`mvn clean package`

  - 运行：java -jar target/<jar-file-name>.jar

  - 自动修改后编译运行：mvn spring-boot:run



### 三、Nacos Server配置相关

Java后端项目application.yaml里有配置nacos的一段：

> spring:
>
>   application:
>
> ​    name: DisasterSimulation
>
>   cloud:
>
> ​    nacos:
>
> ​      discovery:
>
> ​        server-addr: nacos:8848

这里域名nacos应该要映射到具体IP，为了本地运行我就本地配置Nacos Server测试了。

- 下载nacos：https://github.com/alibaba/nacos/releases。下的1.3.2，选tar.gz压缩包。
- cd进nacos/bin目录，运行`sh startup.sh -m standalone`启动nacos，默认端口8848
- 浏览器访问 http://localhost:8848/nacos验证启动成功，账号密码都是nacos
- application.yaml配置中nacos改为server-addr: http://localhost:8848，可以运行后端且nacos处于本地主机
- `sh shutdown.sh`终止nacos






Created On : 2023-09-22
Last Modified : 2023-09-25