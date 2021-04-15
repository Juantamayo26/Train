#!/usr/bin/env python3
import random
import sys

moves = int(sys.argv[1])

n = int(sys.argv[2])
assert n%4 == 0

random.seed(int(sys.argv[3]))

perm = list(range(0, n))

for i in range(moves):
    positions = random.sample(range(0, n), n//2)
    values = [perm[i] for i in positions]
    random.shuffle(values)
    for i, p in enumerate(positions):
        perm[p] = values[i]

print(n)
print(*[i+1 for i in perm])
