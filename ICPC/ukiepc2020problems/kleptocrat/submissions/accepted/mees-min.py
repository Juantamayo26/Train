#!/usr/local/bin/python3
N, M, Q = [int(x) for x in input().split()]
adj = [[] for _ in range(N)]
for _ in range(M):
    a, b, w = [int(x) for x in input().split()]
    a -= 1
    b -= 1
    adj[a].append((b, w))
    adj[b].append((a, w))

cycle_xors = set([0])
stack = [0]
done = [False]*N
done[0] = True
values = [0]*N

while stack:
    cur = stack.pop()
    for nb, w in adj[cur]:
        if done[nb]:
            cycle_xors.add(w ^ values[cur] ^ values[nb])
        else:
            values[nb] = w ^ values[cur]
            done[nb] = True
            stack.append(nb)

cxl = list(cycle_xors)
flippers = [max(cycle_xors)]
while flippers[-1] > 1:
    for i in range(len(cxl)):
        cxl[i] = min(cxl[i], cxl[i] ^ flippers[-1])
    flippers.append(max(cxl))

for _ in range(Q):
    x, y = [int(v) for v in input().split()]
    x -= 1
    y -= 1
    dist = values[x] ^ values[y]
    for flipper in flippers:
        dist = min(dist, dist ^ flipper)
    print(dist)
