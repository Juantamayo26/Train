
from heapq import *
from collections import deque
import time
import sys

n, m, p, g = [int(x) for x in input().split()]

start = [int(x)-1 for x in input().split()]


adj = [[] for _ in range(n)]
for i in range(m):
    u, v, w = [int(x) for x  in input().split()]
    adj[u-1].append((v-1, w))
    adj[v-1].append((u-1, w))

# Dijkstra
dist = [10**18] * n
q = [(0,0)] 
visited = [False] * n
dist[0] = 0
while len(q) > 0:
    d, u = heappop(q)

    if not visited[u]:
        visited[u] = True
        for v, w in adj[u]:
            if d + w < dist[v]:
                dist[v] = d + w
                heappush(q, (dist[v], v))

congestion = [0] * n
total_cost = 0
for person in range(p):
    congestion[start[person]] |= (1 << person)
    total_cost += dist[start[person]]

node_order = list(enumerate(dist))
node_order.sort(key = lambda x : x[1], reverse=True)

index = 0
best_cost = total_cost;
for u, _ in node_order:
    index += 1
    for v, w in adj[u]:
        if dist[v] < dist[u] and dist[v] + w == dist[u]:
            congestion[v] |= congestion[u]

    nr_passing_u = bin(congestion[u]).count("1") 
    current_cost = total_cost - nr_passing_u * dist[u] + nr_passing_u * g;
    best_cost = min(best_cost, current_cost);


print(best_cost)



