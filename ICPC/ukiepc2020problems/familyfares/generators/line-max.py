#!/usr/bin/env python3
from sys import argv

n = 1000
m = n-1
p = 100 
g = 1000000

ps = [1000]*p

print("{} {} {} {}".format(n, m, p, g))
print(" ".join([str(x) for x in ps]))
for i in range(n-1):
    print("{} {} {}".format(i+1, i+2, 1000000))

