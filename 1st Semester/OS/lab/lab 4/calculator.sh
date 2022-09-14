#!/bin/bash
# Simple operations calculator

read -p "Enter two numbers : " a b;
read -p "Enter the operation to perform [(+), -, /, *]: " op;

case $op in
    '+')
        let c=$a+$b;
    ;;
    '-')
        let c=$a-$b;
    ;;
    '/')
        let c=$a/$b;
    ;;
    '*')
        let c=$a*$b;
    ;;
    *)
        op='+';
        let c=$a+$b;
    ;;
esac

echo "$a $op $b = $c"