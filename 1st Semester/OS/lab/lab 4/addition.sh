#!/bin/bash
# Addition of two numbers

read -p "Enter two number for Addition : " a b;

((c=$a + $b))

echo "$a + $b = $c";
