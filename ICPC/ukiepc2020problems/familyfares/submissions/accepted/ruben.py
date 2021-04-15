
from heapq import *
from queue import PriorityQueue
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
#q = PriorityQueue()
#q.put((0,0))
q = [(0,0)] 
visited = [False] * n
dist[0] = 0
while len(q) > 0:
#while not q.empty():
    d, u = heappop(q)
    #d, u = q.get() 


    if not visited[u]:
        visited[u] = True
        for v, w in adj[u]:
            if d + w < dist[v]:
                dist[v] = d + w
                heappush(q, (dist[v], v))
                #q.put((dist[v], v))

congestion = [0] * n
total_cost = 0
for person in range(p):
    total_cost = total_cost + dist[start[person]]

    visited = [False] * n
    q = deque()
    q.append(start[person])
    visited[start[person]] = True
    congestion[start[person]] = congestion[start[person]] + 1
    while q:
        u = q.popleft() 
        for v, w in adj[u]:
            if not visited[v] and dist[v] + w == dist[u]:
                visited[v] = True
                congestion[v] = congestion[v] + 1
                q.append(v)


best_cost = total_cost;
for u in range(n):
    current_cost = total_cost - congestion[u] * dist[u] + congestion[u] * g;
    best_cost = min(best_cost, current_cost);


print(best_cost)



