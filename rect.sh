#!/bin/bash

echo "Enter the number of rows for the rectangle pattern:"
read rows

echo "Enter the number of columns for the rectangle pattern:"
read cols

for ((i=1; i<=rows; i++))
do
    for ((j=1; j<=cols; j++))
    do
        echo -n "* "
    done

    echo ""
done
