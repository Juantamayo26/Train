#!/usr/bin/env python3
import sys
import random
random.seed(sys.argv[1])

w = random.randrange(3*10**4)
h = random.randrange(3*10**4)

c = 4
e = 2*((w-2)+(h-2))
m = (w-2)*(h-2)
print(str.format("{} {} {}", c, e, m))
