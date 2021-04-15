#!/usr/bin/env python3
import sys

r, c = [int(x) for x in sys.argv[1:]]

grid = [[0]*c for _ in range(r)]

dx, dy = 1, 0
x, y = 0, 0
ct = 1

for _ in range(r*c):
    if grid[x][y] == 0:
        grid[x][y] = ct
        ct += 1
    if (0 <= x + dx < r and 0 <= y + dy < c) and \
        (not (0 <= x + 2*dx < r and 0 <= y + 2*dy < c) or 
                (grid[x+2*dx][y + 2*dy] == 0)):
        x += dx
        y += dy
    else:
        dx, dy = -dy, dx

print(r, c)
for row in grid:
    print(*row)
