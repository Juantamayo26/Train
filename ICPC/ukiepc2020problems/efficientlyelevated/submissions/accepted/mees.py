#!/usr/bin/env python3

h, w = [int(x) for x in input().split()]
grid = [[int(x) for x in input().split()] for _ in range(h)]
done = [[False]*w for _ in range(h)]
locs = [(grid[x][y], x, y) for x in range(h) for y in range(w)]
locs.sort(reverse=True)
elevators = 0
stack = []
for v, x, y in locs:
    if done[x][y] or v <= 1:
        continue
    done[x][y] = True
    elevators += 1
    stack.append((x, y))    
    while len(stack):
        curx, cury = stack.pop()
        for nbx, nby in [(curx+1, cury), (curx-1, cury), (curx,cury+1), (curx, cury-1)]:
            if 0 <= nbx < h and 0 <= nby < w and not done[nbx][nby] and \
                    grid[nbx][nby] <= grid[curx][cury]:
                done[nbx][nby] = True
                stack.append((nbx, nby))
print(elevators)
