#!/usr/bin/env python2
import sys
import random

n = int(sys.argv[1])
extram = int(sys.argv[2])
Q = int(sys.argv[3])
random.seed(sys.argv[4])

RI = lambda: random.randrange(0, 2**59)

pi = list(range(1, n+1))
random.shuffle(pi)
# pi[i] = output value of vertex i

# 2 nodes that are connected with 0
# 60 nodes, each having a cycle with the nodes above, of value 2^i (0 <= i < 60)

m = 1 + 120 + (n - 62) + extram
print(str.format("{} {} {}", n, m, Q))

print(str.format("{} {} 0", pi[0], pi[1]))

valueAt = dict()

edges = set()
for i in range(60):
	val = RI()
	while ((2**i)^val > 10**18):
		val = RI()
	print(str.format("{} {} {}", pi[0], pi[2+i], val))
	print(str.format("{} {} {}", pi[2+i], pi[1], (2**i)^val))
for i in range(62, n):
	valueAt[i] = RI()
	print(str.format("{} {} {}", pi[0], pi[i], valueAt[i]))
for i in range(extram):
	a = random.randrange(62, n)
	b = random.randrange(62, n)
	if a > b:
		a,b = b,a
	while a == b or (a,b) in edges:
		a = random.randrange(62, n)
		b = random.randrange(62, n)
		if a > b:
			a,b = b,a

	edges.add((a,b))
	print(str.format("{} {} {}", pi[a], pi[b], valueAt[a] ^ valueAt[b]))

for i in range(Q):
	print(str.format("{} {}", random.randrange(1, n+1), random.randrange(1, n+1)))

