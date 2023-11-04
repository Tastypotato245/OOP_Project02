#!/usr/bin/python3
import random

N = 1000;

for _ in range(N):
    a = random.randint(-99999999999999999999999999999999, 99999999999999999999999999999999)
    b = random.randint(-99999999999999999999999999999999, 99999999999999999999999999999999)
    op = random.randint(0, 2)
    if op == 0:
        op = '+'
    elif op == 1:
        op = '-'
    else:
        op = '"*"'
    print(a, op, b)
