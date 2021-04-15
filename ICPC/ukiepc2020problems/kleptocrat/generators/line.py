#!/usr/bin/env python2
import sys
import random

n = int(sys.argv[1])
Q = 10**5
random.seed(sys.argv[2])

pi = list(range(1, n+1))
random.shuffle(pi)
# pi[i] = output value of v[i]
inv_pi = list(range(n+1))
for i in range(0, n):
	inv_pi[pi[i]] = i

print(str.format("{} {} {}", n, n-1, Q))
for i in range(n-1):
	print(str.format("{} {} {}", pi[i], pi[i+1], random.randrange(0, 10**18+1)))

for i in range(Q):
	print(str.format("{} {}", random.randrange(1, n+1), random.randrange(1, n+1)))
