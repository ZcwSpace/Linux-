#!/bin/bash

echo "Where do you want to go?"
echo "If you want to go Shanghai.Please input 1."
echo "If you want to go Guangzhou.Please input 2."
echo "If you want to go Chengdu.Please input 3."

read -p "Please input that where you want to go:" addr
case $addr in
    1)
        echo "Shanghai"
        ;;
    2)
        echo "Guangzhou"
        ;;
    3)
        echo "Chengdu"
        ;;
    *)
        echo "Error"
        ;;
esac
