echo "Enter angle 1: "
read a1

echo "Enter angle 2: "
read a2

echo "Enter angle 3: "
read a3

sum=`expr $a1 + $a2 + $a3`

if [ $sum -eq 180 ]
then 
	echo "The triangle is valid."
else
	echo "The triangle is invalid."
fi
