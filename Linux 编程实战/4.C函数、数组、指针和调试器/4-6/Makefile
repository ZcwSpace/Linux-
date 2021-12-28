#第一层：显示规则
#目标文件：依赖文件
#[TAB]指令
#
#第一个目标文件是我的最终目标！！！递归
#
#rm hello.i hello.s hello.o hello
#伪目标 .PHONY:
#第二层：变量 =（赋值） +=（追加）:=（常量）
#使用变量 $(变量名) 替换
#第三层：隐含规则 %.c %.o 任意的.c文件或者任意的.o文件    *.c *.o 所有.的.c文件或者任意的.o文件
#第四层：通配符 $@所有的目标文件 $^所有的依赖文件 $<所有的依赖文件的第一个文件
#第五层：函数 
TAR = file
TAR += file1
OBJ=file1.o file2.o
CC:= gcc
RMEF=rm -rf
#file1.c file2.c
#得到可执行文件 file 省去预编译 汇编
$(TAR):$(OBJ)
	$(CC) $^ -o $@
%.o:%.c
	$(CC) -c $^ -o $@
.PHONY:
clearAll:
	$(RMRF) $(OBJ) $(TAR)
clear:
	$(RMRF) $(OBJ) 
	
