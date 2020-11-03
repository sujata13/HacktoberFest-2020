#Program to find LCM of two numbers
import sys

def gcd(a,b):
    if a == 0:
        return b
    return gcd(b % a, a)


def lcm(a,b):
	return (a / gcd(a,b))* b

#Take input from user through command line
a = int(sys.argv[1])
b = int(sys.argv[2])
print(lcm(a, b))
