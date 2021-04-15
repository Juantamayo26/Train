#!/usr/bin/env python3
import sys
import random
random.seed(sys.argv[1])

# Set sizes
n = random.randrange(1, 10000)
m = random.randrange(n-1, min(100000, n*(n-1)//2))
print(str.format("{} {} {}", n, m, 10**5))

# Set values
values = [random.randrange(0, 10**17) for i in range(n)]
edges = set()

# Assure connectedness
for i in range(1,n):
    j = random.randrange(0,i)
    edges.add((i,j))
    print(str.format("{} {} {}", i+1, j+1, values[i] ^ values[j]))
    m -= 1

while m>0:
    i = random.randrange(1, n)
    j = random.randrange(0, i)
    if (i,j) in edges:
        continue
    edges.add((i,j))
    print(str.format("{} {} {}", i+1, j+1, values[i] ^ values[j]))
    m -= 1

for i in range(10**5):
    print(str.format("{} {}", random.randrange(1, n+1), random.randrange(1, n+1)))
