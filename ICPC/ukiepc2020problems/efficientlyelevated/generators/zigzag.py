#!/usr/bin/env python3
import sys

r, c = [int(x) for x in sys.argv[1:]]

grid = [[0]*c for _ in range(r)]

for i in range(0, r, 4):
    grid[i] = [7]*c
    if i + 1 < r:
        grid[i+1] = [0]*(c-1) + [7]
    if i + 2 < r:
        grid[i+2] = [7]*c
    if i + 3 < r:
        grid[i+3] = [7] + [0]*(c-1)

print(r, c)
for row in grid:
    print(*row)
