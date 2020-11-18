#!/bin/sh

a=20
b=10
read name
until [ $b -eq 8 ]
do
	echo "$b"
	b=`expr $b - 1`
done
hello(){
	echo "Hello sagar"
}
hello
