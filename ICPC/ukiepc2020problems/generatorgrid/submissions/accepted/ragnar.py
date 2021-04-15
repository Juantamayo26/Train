def R(): return map(int, input().split())
n, m = R()
g = []
for _ in range(m):
    u, w = R()
    g.append([w, u-1, n])
ws = list(R())
for i in range(n):
    g.append([ws[i], i, (i+1)%n])
g.sort()

par = list(range(n+1))
rank = [0]*(n+1)
def find(i):
    if par[i] == i:
        return i
    else:
        par[i] = find(par[i])
        return par[i]
def same(i,j): return find(i) == find(j)
def merge(i,j):
    i, j = find(i), find(j)
    if i == j: return
    if rank[i] > rank[j]: i,j=j,i
    par[i] = j
    if rank[i] == rank[j]: rank[j] += 1

ans = 0
for w,u,v in g:
    if not same(u,v):
        merge(u,v)
        ans += w

print(ans)

