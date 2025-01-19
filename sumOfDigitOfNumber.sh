#!/bin/bash

echo "Enter a number:"
read number

sum=0
n=$number

while [ $n -gt 0 ]
do
    digit=$((n % 10))
    sum=$((sum + digit))
    n=$((n / 10))
done

echo "The sum of the digits of $number is $sum"
