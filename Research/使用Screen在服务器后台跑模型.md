## 在远程服务器上运行深度学习代码时，可以使用screen命令将程序在后台运行，这样即使关闭了ssh连接，程序也可以继续运行。



以下是使用screen命令将程序在后台运行的步骤：

1. 在ssh连接到远程服务器后，输入以下命令创建一个新的screen窗口：

   ```
   screen -S session_name
   ```

   其中session_name是你为该screen会话指定的名称，可以根据自己的需要进行设置。

2. 运行你的深度学习程序，等待它完成。

3. 按下Ctrl+A键，然后再按下D键，即可将screen会话移到后台运行。

4. 如果需要恢复到screen会话中，可以输入以下命令：

   ```
   screen -r session_name
   ```

   其中session_name是你之前为该screen会话指定的名称。如果只有一个screen会话，则可以省略session_name参数。

5. 如果需要列出当前所有的screen会话，可以输入以下命令：

   ```
   screen -ls
   ```

   系统会返回一个包含所有screen会话的列表。

<<<<<<< HEAD
6. 退出screen会话

   ```
   screen -S session_name -X quit
   ```

   
=======
​	注意：在使用screen命令时，如果你需要退出ssh连接，则不要直接使用Ctrl+C或者关闭终端窗口，而是应该使用以下命令：

```
screen -X -S session_name quit
```

其中session_name是你需要退出的screen会话的名称。这样可以避免screen会话中正在运行的程序被终止。
>>>>>>> 284eabdb2c25dad3cf6ebae74bf42a1cfd87102f



Created On : 2023-04-01
Last Modified : 2023-04-01