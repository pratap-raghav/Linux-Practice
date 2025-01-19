#!/bin/bash

echo "Even numbers from 1 to 10:"
for ((i=2; i<=10; i+=2))
do
    echo $i
done

echo "Odd numbers from 1 to 10:"
for ((i=1; i<=10; i+=2))
do
    echo $i
done
