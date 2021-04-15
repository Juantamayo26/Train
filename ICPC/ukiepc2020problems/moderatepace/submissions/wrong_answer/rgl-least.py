#!/usr/bin/env python3

n = int(input())
a,b,c = map(lambda x: list(map(int, input().split())), range(3))
res = []
for i in range(n):
  res += [sorted((a[i], b[i], c[i]))[0]]
print(' '.join(map(str, res)))
