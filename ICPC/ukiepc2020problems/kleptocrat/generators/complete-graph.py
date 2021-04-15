#!/usr/bin/env python3
import sys
import random
random.seed(sys.argv[1])

n = 1
while n*(n+1)//2 <= 10**5:
    n += 1

print(str.format("{} {} {}", n, n*(n-1)//2, 10**5))
for i in range(n):
    for j in range(i):
        print(str.format("{} {} {}", j + 1, i + 1, random.randrange(0, 10**18 + 1)))

for _ in range(10**5):
    print(str.format("{} {}", random.randrange(0, n) + 1, random.randrange(0, n) + 1))
