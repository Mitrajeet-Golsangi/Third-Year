#!/bin/bash
# String Check

read -p "Enter a String : " str;

if [ $str = "string" ]
then
    echo "Congratulations ! String Matches";
else
    echo "String does not Match :/";
fi
