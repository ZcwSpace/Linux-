#!/bin/bash

#$*中的所有参数看成一个整体，所以这个for循环只会循环一次
for i in "$*"
do
	echo “$i”
done
#$@中的每个参数都是独立的，所以“$@”中有几个参数，就会循环几次
x=1
for y in "$@"
do
	echo "$y"
	x=$(($x+1))
done

	
