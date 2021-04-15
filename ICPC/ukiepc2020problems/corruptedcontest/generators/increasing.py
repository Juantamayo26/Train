#!/usr/bin/env python3
import sys
n = int(sys.argv[1])
print(str.format("{} {}", n, n))
for i in range(1,n+1):
	print(100*i)
