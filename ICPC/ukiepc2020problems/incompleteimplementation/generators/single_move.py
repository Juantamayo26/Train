#!/usr/bin/env python3
import random
import sys

n = int(sys.argv[1])
assert n%4 == 0

random.seed(int(sys.argv[2]))
v1 = list(range(0,n))
v2 = list(range(0,n//2))
random.shuffle(v1)
random.shuffle(v2)
v2 += list(range(n//2, n))
rv1 = [b for a,b in sorted([(v1[i], i) for i in range(n)])]

v = [rv1[v2[v1[i]]] for i in range(n)]
print(n)
print(*[i+1 for i in v])
