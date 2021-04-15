#!/usr/bin/env python3
import random
import sys

n = int(sys.argv[1])
assert n%4 == 0

v = list(range(0,n))
random.seed(int(sys.argv[2]))
random.shuffle(v)
iv = dict(map(reversed,enumerate(v)))

u = [n-1] + list(range(n-1))
w = [ iv[u[v[i]]] for i in range(n) ]

print(n)
print(*[x+1 for x in w])
