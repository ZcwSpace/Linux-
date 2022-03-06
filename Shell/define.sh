#!/bin/bash

echo "$$"

find -name hello.sh &
echo "$!"
