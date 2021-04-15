#!/usr/bin/env python3
import sys
import random

r, c, h, seed = [int(x) for x in sys.argv[1:]]

random.seed(seed)

grid = [[random.randint(0, h) for _ in range(c)] for _ in range(r)]

print(r, c)
for row in grid:
    print(*row)
