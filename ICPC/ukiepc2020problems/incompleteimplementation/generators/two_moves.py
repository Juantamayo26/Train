#!/usr/bin/env python3
import random
import sys

n = int(sys.argv[1])
assert n%4 == 0

random.seed(int(sys.argv[2]))
v = list(range(0,n))
w1 = list(range(0,n//2))
w2 = list(range(n//2,n))
random.shuffle(v)
random.shuffle(w1)
random.shuffle(w2)
w = w1+w2
rv = [b for a,b in sorted([(v[i], i) for i in range(n)])]

u = [rv[w[v[i]]] for i in range(n)]
print(n)
print(*[i+1 for i in u])
