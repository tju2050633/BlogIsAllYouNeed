# macOS下miniOS开发环境配置——bochs+sdl2



## 安装

```shell
brew install bochs # 虚拟机
brew install sdl2	 # GUI
brew install nasm  # 汇编编译器 
```



## 创建软盘

cd进项目目录，此后一直在此目录下。

```shell
bximage
```



选1，fd，1.44M和a.img按默认值。



## 汇编

- boot.asm文件内容：

```assembly
	org 07c00h
	mov ax, cs
	mov ds, ax
	mov es, ax
	call DispStr
	jmp $
DispStr:
	mov ax, BootMessage
	mov bp, ax
	mov cx, 16
	mov ax, 01301h
	mov bx, 000ch
	mov dl, 0
	int 10h
	ret
BootMessage:	db "Hello OS World"
times 510 - ($-$$) db 0
dw 0xaa55


```



- 编译

  ```shell
  nasm boot.asm -o boot.bin
  ```

  

- 写入软盘

  ```shell
  dd if=boot.bin of=a.img bs=512 count=1 conv=notrunc
  ```

  

## 配置启动信息

```shell
cd /usr/local/Cellar/bochs/2.7/share/doc/bochs
open .
```

duplicate bochsrc-sample.txt改名为bochsrc.txt，加入配置信息：

```
romimage: file=$BXSHARE/BIOS-bochs-latest 

vgaromimage: file=$BXSHARE/VGABIOS-lgpl-latest

floppya: 1_44=a.img, status=inserted

# 从软盘启动
boot: floppy
#输出日志
log: bochsout.txt

# 置鼠标不可用
mouse: enabled=0
#键盘配置
keyboard: keymap=#$BXSHARE/keymaps/x11-pc-us.map
#内存容量
megs: 32

#使用GUI界面
display_library: sdl2
```



## 启动bochs

```shell
bochs
```

默认回车选6，然后\<bochs:1> 输入c启动GUI。
