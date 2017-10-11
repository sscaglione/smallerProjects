#!/bin/bash

usage() {
	echo "Usage: $0"
	echo
	echo "-c	CITY	which city to search"
	echo "-f	FORMAT 	which format (text,csv)"
	echo "-s	STATE	which state to search (Indiana)"
	echo
	echo "If no CITY is specified, then all the zip codes for the STATE are displayed"
	exit 1
}

CITY=
FORMAT=text
STATE=Indiana

while getopts "h" OPTION
do
	case $OPTION in
		h)
			usage
			;;
	esac
done

for arg in $@; do
	if [ "$1" = "-c" ]; then
		CITY=$2
		shift
	elif [ "$1" = "-f" ]; then
		FORMAT=$2
		shift
	elif [ "$1" = "-s" ]; then
		STATE=$(echo $2 | sed 's/ /%20/')
		shift
	fi
	shift
done

accessZips() {
	curl -s http://www.zipcodestogo.com/$STATE/
}

findCity() {
	grep -P "/$CITY/"
}

findZip() {
	grep -E -o '>[0-9]{5}<' | sed 's/<//' | sed 's/>//'
}

if [ "$FORMAT" = "text" ]; then
	accessZips | findCity | findZip | sort | uniq
elif ["$FORMAT" = "csv" ]; then
	accessZips | findCity | findZip | tr '\n' ', ' | sort | uniq
else
	accessZips | findCity | findZip | sort | uniq
fi
