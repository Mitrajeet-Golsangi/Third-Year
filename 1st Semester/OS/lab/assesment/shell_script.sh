read -p "Enter a decimal number : " num;

val=0
power=1

while [ $num -ne 0 ];
do
    r=`expr $num % 2`
    val=`expr $r \* $power + $val`
    power=`expr $power \* 10`
    num=`expr $num \/ 2`;
done

echo $val