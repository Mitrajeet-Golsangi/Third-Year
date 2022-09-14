#!/bin/bash

echo ------------------------ For Each Loop ------------------------
for num in 1 2 3 4 5
do
    sum=`expr $num + $num`;
    echo $sum;
done

echo --------------------------- For Loop --------------------------

for ((i=0 ; $i<10 ; i=$i+1))
do
    sum=`expr $num + $num`;
    echo $sum;
done

echo -------------------------- While Loop -------------------------