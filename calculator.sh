i=yes
echo "1. Add"
echo "2. Subtract"
echo "3. Multiply"
echo "4. Divide"

while [ $i = "yes" ]
do	
	echo ""
	read -p "Enter choice: " ch
	echo ""
	read -p "Enter number 1: " n1
	read -p "Enter number 2: " n2
	
	case $ch in
	
	1)
		echo "$n1 + $n2 = $((n1 + n2))"
	;;
	2)	
		echo "$n1 - $n2 = $((n1 - n2))"
	;;
	3)
		echo "$n1 * $n2 = $((n1 * n2))"
	;;
	4)
		echo "$n1 / $n2 = $((n1 / n2))"
	;;
	*)	
		echo "Invalid Choice..."
	;;
	esac
	read -p "Calculate again? (yes/no): " i
	
done
