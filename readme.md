# 静音闹钟

这是一个在`Arduino`开发板上运行的程序

很久以前写的（2019.10.7）

今天想起来之后决定传到`github`存档

设计理念：利用会发彩光的闹钟吸引人们的注意，从而达到提醒效果。

实现效果：①利用超声传感器测距，当距离>40cm或<=4cm时灯泡不发光，当距离介于4-40cm之间时灯泡发彩光，距离越近彩光变化越快。②启动后10s灯泡闪烁，起到闹钟的效果，按下按钮将设置的时间+10s，当超声传感器测得的距离小于4cm时，重置计时器为0s，重置设置的闹铃时间为10s。③在按下按钮时红色LED灯会发光提醒用户“闹钟”装置是否响应了本次按压。

### 运行

"电路.fzz"使用`fritzing`打开，此文件仅为电路设计和展示。

使用`Arduino`IDE将程序编译安装到`Arduino`开发板上，然后启动运行。

`Arduino`开发板长这样：

<img src="demo_board.jpg" width="70%;">
