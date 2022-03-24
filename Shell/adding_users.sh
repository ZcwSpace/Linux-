#/bin/bash

read -p "请输入用户名：" name
read -p "请输入要创建的用户名的数量：" num
read -p "请输入密码：" passwd

if[ !-z $name -a !-z $num -a !-z $passwd ]
    then
        y=$(echo $num|sed 's/^[0-9]*$'//g)
        if [ -z &y ]
            then   
                for ((i=1;i<=num;i=i+1))
                    do
                        useradd $name$i &>/dev/null
                        echo $pass|passwd --stdin $name$i &>/dev/null
                    done
        fi
fi