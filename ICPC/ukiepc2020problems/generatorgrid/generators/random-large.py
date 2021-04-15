#!/usr/bin/env pypy
import sys
import random
random.seed(sys.argv[1])

# bounds are inclusive endpoints: [1,maxa] and [1,maxb]
maxa = 10**9
maxb = 10**9
if len(sys.argv) >= 5:
	# ./generator {seed} {unused} {maxa} {maxb}
	maxa = int(sys.argv[3])
	maxb = int(sys.argv[4])

n = 100000

pairs = []
for i in range(1, n+1):
    if random.random() < 0.75:
        pairs.append((i, random.randrange(1, maxa + 1)))

print(str.format("{} {}", n, len(pairs)))
for x, y in pairs:
    print(str.format("{} {}", x, y))
print(' '.join(str(random.randrange(1, maxb + 1)) for _ in range(n)))
