echo "Enter Cost Price:"
read cp
echo "Enter Selling Price: "
read sp

if [ $sp -gt $cp ]
then 
	echo "Profit"

elif [ $sp -eq $cp ]
then 
	echo "Break-Even"

else
	echo "Loss"
fi
