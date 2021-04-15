#!/usr/bin/env python3
import sys
n = int(sys.argv[1])
print(str.format("{} {}", n, n))
for i in range(n,0,-1):
	print(100*i)
