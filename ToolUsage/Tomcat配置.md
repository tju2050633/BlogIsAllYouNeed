## Tomcat

- 官网`https://tomcat.apache.org`下载压缩包（macOS/Linux就tar.gz）
- 解压后放到`/usr/local`目录下
  - 该目录进入方法：Finder-Go-Go to Folder..(shift command G)，输入/usr/local
  - `/usr/local`目录内容：mysql、Homebrew、Cellar（放brew安装的软件）等，主要用于存放手动安装的软件和程序
- 配环境变量：在~/.bash_profile文件中添加：
  - 方便修改~/.bash_profile等配置文件的方法：Finder-Go-Home进到用户目录，shift command .显示隐藏文件，即可用文本编辑器打开.bash_profile

```
export TOMCAT_HOME=/usr/local/tomcat
export CATALINA_HOME=/usr/local/tomcat
export PATH=$PATH:$TOMCAT_HOME/bin
```

- 修改权限
  - chmod +x /usr/local/tomcat/bin/*.sh
  - chmod 777 /usr/local/tomcat/logs
- 运行tomcat
  - 启动：`sh /usr/local/tomcat/bin/startup.sh`
  - 访问http://localhost:8080验证安装成功
  - 终止：`sh /usr/local/tomcat/bin/shutdown.sh`





Created On : 2023-09-25
Last Modified : 2023-09-25