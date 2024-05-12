#!/bin/bash

echo 1. $((3 + 4))

a=5
b=4
echo 2. $(($a + $b))

a=10
b=3
echo 3. $(($a / $b))

a=10
b=20
((a++))
((--b))
echo 4.1. $a
echo 4.2. $b

a=3
b=5
(( c = a * b ))
echo 5. $c
