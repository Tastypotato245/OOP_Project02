#!/usr/bin/python3
import sys

a = int(sys.argv[1])
op = sys.argv[2]
b = int(sys.argv[3])

print("Output: ", end="")
if op == "+":
    print(a + b)
elif op == "-":
    print(a - b)
else:
    print(a * b)
