#!/usr/bin/env python3
import sys
import random
b = int(sys.argv[1])
random.seed(sys.argv[2])

n = 2 + 2*b
print(str.format("{} {} 1", n, 1 + 3 * b))
print(str.format("1 2 {}", 2**b))
nxt = 1
for e in range(b, 0, -1):
    r = random.randrange(0, 10**18)
    print(str.format("1 {} {}", 2*nxt + 1, r))
    print(str.format("{} {} {}", 2*nxt + 1, 2*nxt+2, 2**e + 2**(e-1)))
    print(str.format("{} 1 {}", 2*nxt+2, r))
    nxt += 1

print("1 2")
