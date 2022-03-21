#!/bin/bash

rate=$(df -h |grep "/dev/nvme0n1p7" | awk '{print $5}' | cut -d "%" -f 1)
if [ $rate -ge 80 ]
    then
        echo "Warning! /dev/nvme0n1p7 is full!"
fi
