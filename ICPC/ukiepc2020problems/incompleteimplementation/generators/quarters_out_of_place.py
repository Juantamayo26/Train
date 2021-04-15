#!/usr/bin/env python3
import random
import sys
n = int(sys.argv[1])
random.seed(int(sys.argv[2]))

assert n%4 == 0
v1 = list(range(0, n//4))
v2 = list(range(n//4, n//2))
v3 = list(range(n//2, (3*n)//4))
v4 = list(range((3*n)//4, n))
random.shuffle(v1)
random.shuffle(v2)
random.shuffle(v3)
random.shuffle(v4)

v = [i+1 for i in v4+v3+v2+v1]

print(n)
print(*v)
