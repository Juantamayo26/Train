#!/usr/bin/env python3
import sys

r, c, x, y = [int(x) for x in sys.argv[1:]]

print(r, c)
for i in range(r):
    for j in range(c):
        print(x if (i + j) % 2 else y, end="")
        if j != c-1:
            print(" ", end="")
    print()
