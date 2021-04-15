#!/usr/bin/env python3
import sys
import random

r, c, k, seed = [int(x) for x in sys.argv[1:]]

random.seed(seed)

grid = [[0]*c for _ in range(r)]

for _ in range(k):
    x1 = random.randint(0, r-1)
    x2 = random.randint(0, r-1)
    y1 = random.randint(0, c-1)
    y2 = random.randint(0, c-1)

    x1, x2 = min(x1, x2), max(x1, x2)
    y1, y2 = min(y1, y2), max(y1, y2)

    h = random.randint(2, 10)

    for x in range(x1, x2+1):
        grid[x][y1] = max(grid[x][y1], h)
        grid[x][y2] = max(grid[x][y2], h)

    for y in range(y1, y2+1):
        grid[x1][y] = max(grid[x1][y], h)
        grid[x2][y] = max(grid[x2][y], h)

print(r, c)
for row in grid:
    print(*row)
