#!/usr/bin/env python3
from sys import argv

n = 1000
m = n-1
p = 100 
g = 1000000

split = 500

ps = [1000]*50 + [500]*50

print("{} {} {} {}".format(n, m, p, g))
print(" ".join([str(x) for x in ps]))
for i in range(1,split):
    print("{} {} {}".format(i, i+1, 1000000))
print("1 501 1000000")
for i in range(split+1,n):
    print("{} {} {}".format(i, i+1, 1000000))
