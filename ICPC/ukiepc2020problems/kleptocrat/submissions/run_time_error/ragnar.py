def R(): return map(int, input().split())
n,m,q = R()
g = [[] for _ in range(n)]
for _ in range(m):
    u,v,w = R()
    g[u-1].append([v-1,w])
    g[v-1].append([u-1,w])
d = [[-1]*n for _ in range(64)]
b = [False] * 64
for i in range(63, -1, -1):
    def dfs(u):
        for v, w in g[u]:
            dv = d[i][u] ^ w
            if d[i][v] == -1:
                d[i][v] = dv
                if not dfs(v): return False
            elif (d[i][v] ^ dv)&(1<<i):
                c = d[i][v] ^ dv
                for s in g:
                    for e in s:
                        if e[1]&(1<<i):
                            e[1] ^= c
                return False
        return True
    d[i][0] = 0
    b[i] = dfs(0)

for _ in range(q):
    x, y = R()
    a = 0
    for i in range(63, -1, -1):
        if b[i]: a += (d[i][x-1]^d[i][y-1])&(1<<i)
    print(a)
