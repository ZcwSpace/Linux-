#!/bin/bash

read  -t 30 -p "请输入你的名字：" name
echo "Name is $name"

read -s -t 30 -p "请输入你的年龄：" age
echo -e "\n"
echo "Age is $age"

read -n 1 -t 30 -p "请输入你的性别：[男/女]" sex
echo -e "\n"
echo "Sex is $sex"

