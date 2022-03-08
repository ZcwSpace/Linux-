#!/bin/bash

git add .
read -p "请输入描述：" description
git commit -m "$description"
git push --set-upstream origin master
