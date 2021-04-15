#!/usr/bin/env python3

import argparse
import lib
import random
from heapq import *

parser = argparse.ArgumentParser()
parser.add_argument("--n", type=int, required=True)
parser.add_argument("--m", type=int, required=True)
parser.add_argument("--max_w", type=int, required=True)
parser.add_argument("--min_w", type=int, default=1)
parser.add_argument("--p", type=int, required=True)
parser.add_argument("--g", type=int, required=True)
parser.add_argument("--dag_size", type=int, required=True)
parser.add_argument("--max_add", type=int, default=10)
parser.add_argument("--min_add", type=int, default=1)
parser.add_argument("--seed")
args = parser.parse_args()

if args.seed is not None:
    lib.seed(args.seed)

#lib.seed(str(1))
g = lib.random_tree_uniform(args.n)
g = lib.with_random_weights(g, min_weight=args.min_w, max_weight=args.max_w)

people = [random.randint(1,args.n) for _ in range(args.p)]

# Calculate distances
adj = [[] for _ in range(args.n)]
for u,v,c in g:
    adj[u].append((v, c))
    adj[v].append((u, c))

dist = [10**18] * args.n
q = [(0,0)]
dist[0] = 0
while len(q) > 0:
    d, u = heappop(q)
    if d > dist[u]: continue
    dist[u] = d
    for v, c in adj[u]:
        if d+c < dist[v]:
            heappush(q, (d+c, v))

g_fast = set([(a,b) for (a,b,_) in g])


while len(g) < args.m:
    u = random.randint(0,args.n-1)
    v = random.randint(0,args.n-1)
    if u == v or  (u,v) in g_fast or (v,u) in g_fast:
        continue
    cost = abs(dist[u] - dist[v])

    if cost == 0 or cost > 10**6:
        continue

    if len(g) >= args.dag_size:
        cost += random.randint(args.min_add, args.max_add)

    cost = min(cost, 10**6)

    g.append((u,v,cost))
    g_fast.add((u,v))

g = lib.shuffle_edges(g)

print("{} {} {} {}".format(args.n, args.m, args.p, args.g))
print(*people)
lib.output_edges(args.n, g)
