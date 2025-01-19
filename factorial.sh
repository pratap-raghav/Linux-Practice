#!/bin/bash

echo "Enter a number to calculate its factorial:"
read number

factorial=1

for ((i=1; i<=number; i++))
do
    factorial=$((factorial * i))
done

echo "The factorial of $number is $factorial"
