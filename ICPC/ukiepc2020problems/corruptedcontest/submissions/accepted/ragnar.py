#!/usr/bin/env python3
from itertools import accumulate
n, p = map(int, input().split())
a = [int(input()) for _ in range(n)] + [0]
d = list(1 if a[i+1] < a[i] else 0 for i in range(n))
if a[0] == 0: print(*(0 for _ in range(n)))
elif sum(d) < p: print('ambiguous')
else: print(*(p - x for x in accumulate([0] + d[:n-1])))
