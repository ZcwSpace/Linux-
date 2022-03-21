#!/bin/bash

read -p "please input a filename:" name
if [ -z $name ]
    then
        echo "Errno,please input a filename!"
        exit 1
elif [ !-e $name ]
    then   
        echo "Your input is not a filename!"
        exit 2
elif [ -f $name ]
    then   
        echo "$name is a regular file!"
elif [ -d $name ]
    then   
        echo "$name is a directory file!"
else
    echo "$name is an other file!"
fi

