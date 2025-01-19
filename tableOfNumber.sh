#!/bin/bash

echo "Enter a number to print its multiplication table:"
read number

echo "Multiplication table for $number:"
for ((i=1; i<=10; i++))
do
    result=$((number * i))
    echo "$number x $i = $result"
done
