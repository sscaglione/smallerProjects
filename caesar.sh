#!/bin/sh

usage(){
	echo "Usage: $0 [rotation]"
	echo
	echo "This program will read from stdin and rotate (shift right) the text by"
	echo "the specified rotation. If none is specified, then the default value is"
	echo "13."
	exit 1
}

if [ $# -eq 0 ]; then
	key=13
elif [ "$1" = "-h" ]; then
		usage
else
	key=$(($1%26))
fi

lcalpha=abcdefghijklmnopqrstuvwxyz

ucalpha=ABCDEFGHIJKLMNOPQRSTUVWXYZ

upperbound=`expr $key + 1`

lc2=`(echo $lcalpha | cut -c 1-$key)`
lc1=`(echo $lcalpha | cut -c $upperbound-26)`

uc2=`(echo $ucalpha | cut -c 1-$key)`
uc1=`(echo $ucalpha | cut -c $upperbound-26)`

tr $lcalpha$ucalpha $lc1$lc2$uc1$uc2


