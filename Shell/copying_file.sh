#/bin/bash

ls *sh>ls.log

y=1
sum=0
for i in $(cat ls.log)
    do
        sum=$[$y+$sum]
    done
echo "目前总共写了$sum个脚本文件"