#!/usr/bin/env python3
import sys
import random
random.seed(sys.argv[1])

c = 4
e = 2*random.randrange(0, 10**4)
m = random.randrange(0, 10**8)
print(str.format("{} {} {}", c, e, m))
