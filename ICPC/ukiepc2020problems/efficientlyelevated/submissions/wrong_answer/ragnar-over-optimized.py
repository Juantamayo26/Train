h, w = map(int, input().split())
board = [[0]*(w+2)] + [[0]+list(map(int, input().split()))+[0] for _ in range(h)] + [[0]*(w+2)]
done = [[False for _ in range(w+2)] for _ in range(h+2)]

dxy = [(1,0),(-1,0),(0,1),(0,-1)]

ans = 0
for r in range(1,h+1):
    for c in range(1,w+1):
        if done[r][c]: continue
        v = board[r][c]
        if v <= 1: continue
        q = [(r,c)]
        ok = True
        while ok and len(q) > 0:
            x, y = q.pop()
            if done[x][y] is True: continue
            done[x][y] = True
            for dx, dy in dxy:
                if board[x+dx][y+dy] > v: ok = False
                if board[x+dx][y+dy] == v: q.append((x+dx,y+dy))
        if ok: ans += 1

print(ans)
