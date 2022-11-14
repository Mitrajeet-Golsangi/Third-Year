#!/bin/bash

arr=($(seq 1 10))

sum=0;

for num in ${arr[@]}; do
    ((sum=$sum+$num))
done

echo "Sum of numbers is : $sum";

declare -a arr1

arr1[0]="cat";
arr1[1]="dog";
arr[2]="cow";
for i in ${!arr1[@]}; do
    echo "Element $i is ${arr1[$i]}"
done
