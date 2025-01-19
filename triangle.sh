#!/bin/bash

echo "Enter the number of rows for the triangle pattern:"
read rows

for ((i=1; i<=rows; i++))
do
    for ((j=i; j<rows; j++))
    do
        echo -n "  "
    done

    for ((k=1; k<=2*i-1; k++))
    do
        echo -n " *"
    done

    echo ""
done

