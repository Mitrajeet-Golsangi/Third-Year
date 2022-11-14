#!/bin/bash
# Simple operations calculator

case $2 in
    'add')
        op='+'
        let c=$1+$3;
    ;;
    'sub')
        op='-'
        let c=$1-$3;
    ;;
    'div')
        op='/'
        let c=$1/$3;
    ;;
    'mul')
        op='*'
        let c=$1*$3;
    ;;
    *)
        op='add';
        let c=$1+$3;
    ;;
esac

echo "$1 $op $3 = $c"