#!/usr/bin/env pypy
import sys

n = 10**5
m = n

#        O
#       /|
#      c d
#     /  |
# -a-O-b-O
a = int(sys.argv[1])
b = int(sys.argv[2])
c = int(sys.argv[3])
d = int(sys.argv[4])

print(str.format("{} {}", n, m))
for i in range(1, n+1):
    print(str.format("{} {}", i, c if i%2 == 0 else d))
print(' '.join(map(str, [(a if i%2 == 0 else b) for i in range(n)])))
