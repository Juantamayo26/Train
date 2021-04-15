#!/usr/bin/env python3
import sys

r, c = [int(x) for x in sys.argv[1:]]

grid = [[0]*r for _ in range(c)]

for i in range(0, c, 4):
    grid[i] = [7]*r
    if i + 1 < c:
        grid[i+1] = [0]*(r-1) + [7]
    if i + 2 < c:
        grid[i+2] = [7]*r
    if i + 3 < c:
        grid[i+3] = [7] + [0]*(r-1)

grid = [[grid[i][j] for i in range(c)] for j in range(r)]

print(r, c)
for row in grid:
    print(*row)
