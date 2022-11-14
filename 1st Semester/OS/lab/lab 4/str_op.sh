#!/bin/bash
# String Check

read -p "Enter a String : " str;

echo ------------------------------------ String Length -------------------------------------

echo String Length = ${#str};

echo --------------------------------- Variable as String -----------------------------------

echo Variable as String = $str;

echo --------------------------------- String concatination ---------------------------------

read -p "Enter another string : " str2;

concat="$str$str2";

echo $concat

echo -------------------------------- String Case Conversion -------------------------------- 

echo $str | tr '[:lower:]' '[:upper:]'

echo ------------------------------------ String Splice -------------------------------------

echo ${str:5}

echo ------------------------------------ String Compare ------------------------------------

if [ $str = "string" ]
then
    echo "Congratulations ! String Matches";
else
    echo "String does not Match :/";
fi
