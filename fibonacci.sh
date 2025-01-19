#!/bin/bash

fibo() {
	i=$(( $1-2 ))
	num1=0
	num2=1
	echo "$num1"
	echo "$num2"
	if [ $i -le 0 ]
	then
		return
	fi
	
	while [ $i -ne 0 ]
	do
		temp=$num1
		num1=$num2
		num2=$(( num1+temp ))
		echo "$num2"
		((i--))
	done
}
read -p "Enter Number(<1): " num
fibo num
