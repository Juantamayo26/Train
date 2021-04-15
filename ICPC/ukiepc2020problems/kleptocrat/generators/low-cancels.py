#!/usr/bin/env python2
import sys
import random

n = int(sys.argv[1])
m = int(sys.argv[2])
Q = int(sys.argv[3])
# How many 'parts' should there exist inside this graph?
parts = int(sys.argv[4])
low_bits = int(sys.argv[5])
random.seed(sys.argv[6])

RHI = lambda: random.randrange(0, 2**(59 - low_bits)) * (2**low_bits)
RLO = lambda: random.randrange(0, 2**low_bits)

pi = list(range(1, n+1))
random.shuffle(pi)
# pi[i] = output value of vertex i

# {0, 1, 2, ..., n-1} -> {0,1,..., parts-1}
div = (n+parts-1)//parts
comp_val = [ RHI() for i in range(parts) ]
comp_val[0] = 0

print(str.format("{} {} {}", n, m, Q))

edges = set()

# make graph 'connected'
for i in range(1, n):
	j = random.randrange(0, i)
	print(str.format("{} {} {}", pi[j], pi[i], comp_val[j//div] ^ comp_val[i//div] ^ RLO()))
	edges.add((j,i)) # j < i

for i in range(m - n + 1):
	a = random.randrange(62, n)
	b = random.randrange(62, n)
	if a > b:
		a,b = b,a
	while a == b or (a,b) in edges:
		a = random.randrange(62, n)
		b = random.randrange(62, n)
		if a > b:
			a,b = b,a

	edges.add((a,b)) # a < b
	print(str.format("{} {} {}", pi[a], pi[b], comp_val[a//div] ^ comp_val[b//div] ^ RLO()))

for i in range(Q):
	print(str.format("{} {}", random.randrange(1, n+1), random.randrange(1, n+1)))

