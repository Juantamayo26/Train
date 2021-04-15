import sys

mutations = [(0,-1),(0,1),(-1,0),(1,0)]
towers = 0

def check(k,x,y):
    global visited
    global mutations
    global mx
    global my
    for dx,dy in mutations:
        nx = x+dx
        ny = y+dy
        if nx<0 or nx >= mx or ny<0 or ny >= my:
            continue
        if not visited[ny][nx]:
            nk = mtrx[ny][nx]
            if nk<=k:
                visited[ny][nx] = True
                check(nk,nx,ny)

lines = sys.stdin.readlines()
my,mx = [int(x) for x in lines[0].split()]

mtrx = [[int(x) if int(x)!=1 else 0 for x in line.split()] for line in lines[1:]]

visited = []
for _ in range(len(mtrx)):
    new = []
    for _ in range(len(mtrx[0])):
        new.append(False)
    visited.append(new[:])

maxs = {}

for y,r in enumerate(mtrx):
    for x,c in enumerate(r):
        if c not in maxs.keys():
            maxs[c] = []
        maxs[c].append( (x,y) )

try:
    for x,y in maxs[0]:
        visited[y][x] = True
except KeyError:
    pass

for k in sorted(maxs.keys(), reverse=True):
    for x,y in maxs[k]:
        if not visited[y][x]:
            # This is the highest point, and now we need to findout if its connected
            towers += 1
            check(k,x,y)
print(towers)
