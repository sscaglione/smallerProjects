#!/bin/env python2.7

import sys

for num in range(101):
	if num % 15 == 0:
		print "FizzBuzz"
	elif num % 3 == 0:
		print "Fizz"
	elif num % 5 == 0:
		print "Buzz"
	else:
		print num
