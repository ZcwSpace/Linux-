#circle.c circle.h cube.c cube.h main.c main.h
#得到可执行文件 test 省去预编译 汇编
file:file1.o file2.o
	gcc file1.o file2.o -o file
file1.o:file1.c
	gcc -c file1.c -o file1.o
file2.o:file2.c
	gcc -c file2.c -o file2.o
.PHONY:
clearAll:
	rm -rf file1.o file2.o file file1.c~ file2.c~
clear:
	rm -rf file1.o file2.o file1.c~ file2.c~
	
