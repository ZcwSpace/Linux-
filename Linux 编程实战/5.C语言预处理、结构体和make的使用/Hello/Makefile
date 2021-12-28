#是注释。
#第一层：显示规则
#目标文件：依赖文件
#[TAB]指令
#
#第一个目标文件是我的最终目标！！！递归
#
#rm hello.i hello.s hello.o hello
#伪目标 .PHONY:
#make clear执行
#
#连接
hello:hello.o
	gcc hello.o -o hello
#汇编
hello.o:hello.s
	gcc -c hello.s -o hello.o
#编译
hello.s:hello.i
	gcc -S hello.i -o hello.s
#预处理
hello.i:hello.c
	gcc -E hello.c -o hello.i
.PHONY:
clearAll:
	rm hello.i hello.s hello.o hello
clearPart:
	rm hello.i hello.s hello.o
