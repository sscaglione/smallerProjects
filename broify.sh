#!/bin/sh

usage() {
	echo "Usage $0"
	echo
	echo "-d DELIM	Use this as the comment delimiter."
	echo "-W		Don't strip empty lines."
	exit 1
}

STRIPPER=1
DELIM=#

while getopts "hWd:" OPTION
do
	case $OPTION in
		h)
			usage
			;;
		W)
			STRIPPER=0
			;;
		d)
			DELIM=$OPTARG
			;;
	esac
done

stripping() {
	if [ $STRIPPER -eq 1 ]; then
		sed -E '/^$/d'
	else
		cat
	fi
}

sed -E 's|'$DELIM'.*$||g' | sed -E 's|\s*$||g' | stripping
