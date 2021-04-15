#!/usr/bin/env python3
import sys
import random

w = int(sys.argv[1])
h = int(sys.argv[2])

c = 4
e = 2*((w-2)+(h-2))
m = (w-2)*(h-2)
print(str.format("{} {} {}", c, e, m))
