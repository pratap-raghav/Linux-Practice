#!/bin/bash

echo "Enter Character: "
read ch

if [[ "$ch" =~ [A-Za-z] ]]; then
    echo "Alphabet"
elif [[ "$ch" =~ [0-9] ]]; then
    echo "Digit"
else
    echo "Special Character"
fi
