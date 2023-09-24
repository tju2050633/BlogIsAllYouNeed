## Java版本控制



### 一、查看JDK版本

查看当前使用JDK**版本**

```
java -version
```

> java version "1.8.0_371"
>
> Java(TM) SE Runtime Environment (build 1.8.0_371-b11)
>
> Java HotSpot(TM) 64-Bit Server VM (build 25.371-b11, mixed mode)

（已切换到JDK1.8）



**查看本地已安装版本**

```
/usr/libexec/java_home -V
```

> Matching Java Virtual Machines (3):
>     18.0.2.1 (x86_64) "Oracle Corporation" - "Java SE 18.0.2.1" /Library/Java/JavaVirtualMachines/jdk-18.0.2.1.jdk/Contents/Home
>     1.8.371.11 (x86_64) "Oracle Corporation" - "Java" /Library/Internet Plug-Ins/JavaAppletPlugin.plugin/Contents/Home
>     1.8.0_371 (x86_64) "Oracle Corporation" - "Java SE 8" /Library/Java/JavaVirtualMachines/jdk-1.8.jdk/Contents/Home
> /Library/Java/JavaVirtualMachines/jdk-18.0.2.1.jdk/Contents/Home

中间的不管，目前/Library/Java/JavaVirtualMachines下有两个JDK版本1.8和18。



### 二、切换JDK版本

假设目前`java -v`输出JDK18，需要切换到1.8:

**设置环境变量，路径到/Library/Java/JavaVirtualMachines中找**

```
export JAVA_HOME=/Library/Java/JavaVirtualMachines/jdk-1.8.jdk/Contents/Home
```

**export方法必须每次重启终端都重新设置一次。**

此外，maven需要指定JAVA_HOME环境变量，否则无法使用。





配置/etc/profile目前有问题，待解决。



Created On : 2023-09-24
Last Modified : 2023-09-24