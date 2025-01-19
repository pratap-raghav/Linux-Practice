#!/bin/bash

armStrongNum() {
	temp=$1
	arm=0
	c=0
	while [ $temp -ne 0 ]
	do
		temp=$(( temp/10 ))
		((c++))
	done
	temp=$1
	while [ $temp -ne 0 ]
	do
		x=$(( temp%10 ))
		temp=$(( temp/10 ))
		arm=$(( arm+x**c ))
	done
	if [ $1 -eq $arm ]
	then
		echo "$1 is an Armstrong Number."
	else
		echo "$1 is not an Armstrong Number."
	fi
}

read -p "Enter Number: " num
armStrongNum $num
