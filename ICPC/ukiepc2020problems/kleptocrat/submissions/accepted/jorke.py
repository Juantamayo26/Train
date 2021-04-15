#!/usr/bin/python3

# Total running time:
# O(E*C + Q*C)
# Where V = node count, E = edge count, C = log(max edge value)

# Read input graph
# O(V+E)
n,m,q = map(int,input().split())
graph = [[] for i in range(n)]
for i in range(m):
    x,y,d = map(int,input().split())
    graph[x-1].append((y-1,d))
    graph[y-1].append((x-1,d))

# Find paths from node 0 and a cycle base using DFS
# O(E*C)
XORpath = [-1]*n
stack = [(0,0)]
equivalences = [-1]*65
while len(stack)>0:
    node,value = stack.pop()
    if XORpath[node] == -1:
        # A path
        XORpath[node] = value

        # Recurse
        for neighbor,distance in graph[node]:
            stack.append((neighbor,value ^ distance))
    else:
        # A cycle
        cycle = value^XORpath[node]

        # Place in cycle base
        # O(C)
        while cycle>0:
            length = cycle.bit_length()
            if equivalences[length] == -1:
                equivalences[length] = cycle
            cycle ^= equivalences[length]

# Answer queries
# O(Q*C)
for i in range(q):
    x,y = map(int,input().split())
    x -= 1
    y -= 1
    # A path
    distance = XORpath[x] ^ XORpath[y]

    # Reduce to shortest path
    for cycle in reversed(equivalences):
        if cycle == -1:
            continue
        if distance > distance^cycle:
            distance ^= cycle
    print(distance)
