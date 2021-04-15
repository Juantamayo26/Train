#!/usr/bin/env python3
import random
import sys
n = int(sys.argv[1])
random.seed(int(sys.argv[2]))

assert n%4 == 0
v = list(range(1, n+1))
random.shuffle(v)
print(n)
print(*v)
