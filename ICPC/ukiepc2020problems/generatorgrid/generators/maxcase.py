#!/usr/bin/env python3
print("100000 100000")
n = 10**5
for i in range(1, n+1):
    print(str.format("{} 1000000000", i))
print(' '.join(str(10**9) for _ in range(n)))
