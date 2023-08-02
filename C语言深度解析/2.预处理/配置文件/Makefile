all:
	gcc write.c -o write

configure:
	#执行脚本文件config,config会创建congfig.h
	#如果传给脚本的参数是win,就往config.h中写入#define WINDOWS
	#如果传给脚本的参数是Linux,就往config.h中写入#define LINUX
	#./config.sh win 
	./config.sh linux


clean:
	#执行脚本文件config,传入参数为clean
	#脚本文件会删除可执行文件helloworld和config.h
		./config.sh clean 