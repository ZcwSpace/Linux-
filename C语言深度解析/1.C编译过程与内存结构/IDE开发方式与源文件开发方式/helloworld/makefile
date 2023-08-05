# Project: helloworld
# Makefile created by Red Panda C++ 2.7

CPP      = g++
CC       = gcc
OBJ      = main.o
LINKOBJ  = main.o
CLEANOBJ  =  main.o helloworld
LIBS     =  -L"/home/zcw/Documents/Linux-/C语言深度解析/2.预处理/include/test"
INCS     =  
CXXINCS  =  
BIN      = helloworld
CXXFLAGS = $(CXXINCS)  -g3 -pipe -Wall -Wextra -D__DEBUG__
CFLAGS   = $(INCS)  -g3 -pipe -Wall -Wextra -D__DEBUG__
RM       = rm -rf

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	-${RM} $(CLEANOBJ) > /dev/null 2>&1

$(BIN): $(OBJ)
	$(CC) $(LINKOBJ) -o $(BIN) $(LIBS)

main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS) 
