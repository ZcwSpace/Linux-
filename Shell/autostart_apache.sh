#!/bin/bash
port=$(nmap -sT 192.168.1.1 |grep tcp |grep http$| awk '{print $2}')
if [ $port=="open" ]
    then
        echo "$(date) httped is ok!!">>/tmp/httped_acc.log
    else
        /etc/rc.d/init.d/httped restart &>/dev/null
        echo "$(date) httped reboot!!">>/tmp/httped_err.log
fi