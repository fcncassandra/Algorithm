# Data Structure

## Jupyter环境搭建（可跳过）

本数据结构部分的C++代码均在jupyter下运行

[windows的ubuntu系统安装](https://blog.csdn.net/qq_20084101/article/details/82316263)

[windows的jupyter环境C++内核安装](https://blog.csdn.net/qq_20084101/article/details/89494474)

执行conda install jupyter之前最好换一个源：

```
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud/conda-forge  
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/free/  
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/main/  
conda config --set show_channel_urls yes  
```

然后安装C++内核，快安装完时会有一些safety error，忽略他们：

```
conda install xeus-cling
```

二者桥接的关系比较特殊，应该是桥接模式，可以浏览器访问localhost来进入页面，powershell执行jupyter启动的时候看不到token，进入页面需要输入，后面可以自己配置密码

```
jupyter lab 
```

xeus但支持的不是很好，递归都写不了，会报函数重载的错误

https://github.com/jupyter-xeus/xeus-cling/issues/345

## 在windows使用vscode

参考：[Visual Studio Code (vscode) 配置 C / C++ 环境](https://www.cnblogs.com/bpf-1024/p/11597000.html)

- 1 安装vscode

- 2 安装cpptool工具，搜索：c/c++，我下的版本是1.1.3

- 3 下载MinGW，我下的是[MinGW-W64 GCC-8.1.0](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/8.1.0/threads-posix/seh/x86_64-8.1.0-release-posix-seh-rt_v6-rev0.7z/download)，然后我解压到了F:\coding\mingw64

- 4 配置用户的环境变量F:\coding\mingw64\bin，然后cmd执行g++来判断是否配置成功

- 5 确定工作目录，我的目录是：E:\documents\Acwing，然后按参考的教程配置launch.json，这个文件实际是在E:\documents\Acwing\\.vscode这个下面

  ```
  {
      "version": "2.0.0",
      "tasks": [
          {
              "label": "task g++",
              "type": "shell",
              "command": "F:\\coding\\mingw64\\bin\\g++.exe",
              "args": [
                  "-g",
                  "${file}",
                  "-o",
                  "${fileDirname}\\${fileBasenameNoExtension}.exe"
              ],
              "options": {"cwd": "F:\\coding\\mingw64\\bin"},
              // "options": {"cwd": "E:\\documents\\Acwing"},
              "problemMatcher": [ "$gcc" ],
              "group": "build"
          }
      ]
  }
  ```

- 6 配置tasks.json

  ```
  {
      "version": "2.0.0",
      "tasks": [
          {
              "label": "task g++",
              "type": "shell",
              "command": "F:\\coding\\mingw64\\bin\\g++.exe",
              "args": [
                  "-g",
                  "${file}",
                  "-o",
                  "${fileDirname}\\${fileBasenameNoExtension}.exe"
              ],
              "options": {"cwd": "F:\\coding\\mingw64\\bin"},
              // "options": {"cwd": "E:\\documents\\Acwing"},
              "problemMatcher": [ "$gcc" ],
              "group": "build"
          }
      ]
  }
  ```

- 7 启动生效
- 其他配置：①双屏：CTRL+Shift+P，输入: > Workspace: Duplicate As Workspace in New Window

## vscode使用Jupyter

因为笔者还是习惯使用Jupyter去记录笔记，所以这里[VSCode中使用jupyter notebook](https://blog.csdn.net/JohnJim0/article/details/106125793)

