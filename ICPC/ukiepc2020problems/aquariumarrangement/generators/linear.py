#!/usr/bin/env python3
import sys

# Reads two ranges l r step and puts piranhas at those positions.
# Note that as usual ranges are right exclusive, and positions are numbered from 0.
n, sl, sr, ss, tl, tr, ts = map(int, sys.argv[1:])
s = list(range(sl+1, sr+1, ss))
t = list(range(tl+1, tr+1, ts))
assert len(s) == len(t)
print(n, len(s))
print(*s)
print(*t)
