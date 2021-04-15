# n,m <= 10^5, p <= 100
from heapq import *
n, m, p, gc = map(int, input().split())
ps = list(map(lambda x: int(x)-1, input().split()))
g = [[] for _ in range(n)]
for _ in range(m):
    u,v,c=map(int, input().split())
    g[u-1].append((v-1, c))
    g[v-1].append((u-1, c))

# Dijkstra
dist = [10**18] * n
q = [(0,0)]
dist[0] = 0
while len(q) > 0:
    d, u = heappop(q)
    if d > dist[u]: continue
    dist[u] = d
    for v, c in g[u]:
        if d+c < dist[v]:
            heappush(q, (d+c, v))
            dist[v] = d+c


# Walk over tree
totaldist = sum(dist[u] for u in ps)
ans = totaldist
cnt = [[0]*p for _ in range(n)]
for i, u in enumerate(ps): cnt[u][i] += 1
o = list(range(n))
o.sort(key=lambda u: dist[u], reverse=True)
for u in o:
    cs = [cnt[u]]
    for v, c in g[u]: 
        if dist[v] == dist[u] + c: cs.append(cnt[v])
    cnt[u] = list(map(max, zip(*cs)))
    ans = min(ans, totaldist + sum(cnt[u]) * (gc - dist[u]))

print(ans)
