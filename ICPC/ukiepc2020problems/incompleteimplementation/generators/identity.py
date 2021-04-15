#!/usr/bin/env python3
import random
import sys
n = int(sys.argv[1])

assert n%4 == 0

print(n)
print(*range(1,n+1))
