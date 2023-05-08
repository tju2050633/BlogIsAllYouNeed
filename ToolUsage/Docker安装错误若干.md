
 Docker安装参考博客：https://cloud.tencent.com/developer/article/1744822

## 1. 命令行安装Docker时cask参数问题

**错误提示**：
> 使用brew安装Docker命令：brew cask install docker
> 提示cask参数已经废弃，应该使用--cask

---

**解决**：
> brew install docker --cask

## 2. 拉取镜像时报错

**错误提示**：
> 拉取镜像命令：docker pull oracleinanutshell/oracle-xe-11g
> Cannot connect to the Docker daemon at unix:///var/run/docker.sock. Is the docker daemon running?

---

**解决**：
> 启动Docker服务：open /Applications/Docker.app
> 即打开桌面应用

## 3. 运行镜像时报错

**错误提示**：
> 运行镜像命令：docker run -d -p 49161:1521 -e ORACLE_ALLOW_REMOTE=true oracleinanutshell/oracle-xe-11g
> Error response from daemon: Ports are not available: exposing port TCP 0.0.0.0:49161 -> 0.0.0.0:0: listen tcp 0.0.0.0:49161: bind: address already in use.

---

**解决**：
>  Docker界面左侧“images”，勾选拉取的镜像，命名容器Test，Run，即将上面的命令换成界面操作
> 进入容器：docker exec -it Test /bin/bash
> 连接到oracle服务：
> su oracle
> cd $ORACLE_HOME
> bin/sqlplus / as sysdba
> 创建表空间：
> /# /u01/app/oracle/oracle_test/ 路径必须存在
> create tablespace trunk datafile '/u01/app/oracle/oracle_test/trunk.dbf' size 200M;




Created On : 2023-02-28
Last Modified : 2023-02-28