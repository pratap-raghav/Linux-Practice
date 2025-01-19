#!/bin/bash

echo "Enter the size of the hollow square pattern:"
read size

# Print first row
for ((i=1; i<=size; i++))
do
    echo -n "* "
done
echo ""

# Print middle rows
for ((i=2; i<=size-1; i++))
do
    echo -n "* "
    for ((j=2; j<=size-1; j++))
    do
        echo -n "  "
    done
    echo "* "
done

# Print last row
if [ $size -gt 1 ]; then
    for ((i=1; i<=size; i++))
    do
        echo -n "* "
    done
    echo ""
fi
