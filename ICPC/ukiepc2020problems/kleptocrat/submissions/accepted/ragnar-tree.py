def R(): return map(int, input().split())
n,m,q = R()
g = [[] for _ in range(n)]
for _ in range(m):
    u,v,w = R()
    g[u-1].append([v-1,w])
    g[v-1].append([u-1,w])
d = [0] + [None]*(n-1)
e, s = [], [0]
while len(s) > 0:
    u = s.pop()
    for v, w in g[u]:
        dv = d[u] ^ w
        if d[v] is None:
            d[v] = dv
            s.append(v)
        else:
            c = d[v] ^ dv
            for x in e:
                if c ^ x < x: c ^= x
            if c not in e:
                e2 = set([c])
                for x in e: e2.add(min(x, x^c))
                e = sorted(list(e2), reverse=True)

for _ in range(q):
    x, y = R()
    a = d[x-1] ^ d[y-1]
    for x in e: a = min(a, a^x)
    print(a)
