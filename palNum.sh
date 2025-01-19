#!/bin/bash

palindrome() {
	temp=$1
	pali=0
	
	while [ $temp -ne 0 ]
	do
		x=$(( temp%10 ))
		temp=$(( temp/10 ))
		pali=$(( pali*10 ))
		pali=$(( pali+x ))
	done
	if [ $1 -eq $pali ]
	then
		echo "$1 is a Palindrome No."
	else
		echo "$1 is not a Palindrome No."
	fi
}

read -p "Enter Number: " num
palindrome $num
