#!/bin/bash

prime() {
	i=2
	num=$1
	flag=0
	while [ $i -ne $num ]
	do
		if [ $(( num%i )) -eq 0 ]
		then	
			flag=1
			break
		fi
		((i++))
	done
	if [ $flag -eq 0 ]
	then
		echo "$num is a Prime Number."
	else
		echo "$num is Composite Number."
	fi
}
read -p "Enter Number: " n
prime $n
