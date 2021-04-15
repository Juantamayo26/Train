#!/usr/bin/env python3
from sys import argv
import random

random.seed(int(argv[4]))

n = int(argv[1])
m = n-1
p = int(argv[2]) 
g = int(argv[3]) 

ps = sorted(random.sample(range(2, n+1), p))

print("{} {} {} {}".format(n, m, p, g))
print(" ".join([str(x) for x in ps]))
for i in range(n-1):
    print("{} {} {}".format(i+1, i+2, 1))

