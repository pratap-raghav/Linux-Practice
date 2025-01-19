#!/bin/bash

# Function to convert binary to decimal
binary_to_decimal() {
    echo "Enter a binary number:"
    read binary
    decimal=0
    base=1

    while [ $binary -gt 0 ]
    do
        last_digit=$((binary % 10))
        binary=$((binary / 10))
        decimal=$((decimal + last_digit * base))
        base=$((base * 2))
    done

    echo "The decimal equivalent is $decimal"
}

# Function to convert decimal to binary
decimal_to_binary() {
    echo "Enter a decimal number:"
    read decimal
    binary=""

    while [ $decimal -gt 0 ]
    do
        remainder=$((decimal % 2))
        binary="$remainder$binary"
        decimal=$((decimal / 2))
    done

    echo "The binary equivalent is $binary"
}

echo "Choose an option:"
echo "1. Convert binary to decimal"
echo "2. Convert decimal to binary"
read option

case $option in
    1) binary_to_decimal ;;
    2) decimal_to_binary ;;
    *) echo "Invalid option" ;;
esac
