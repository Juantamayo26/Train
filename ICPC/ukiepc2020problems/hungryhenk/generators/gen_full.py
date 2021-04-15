#!/usr/bin/env python3
from sys import argv

import random

maxN = 100  # Number of lines
maxD = 42  # Number of dishes per line
maxC = 20  # Number of characters per dish

random.seed(argv[1])
print(maxN)
for _ in range(maxN):
    print(maxD, *["".join(chr(random.randint(ord('a'), ord('z'))) for _ in range(maxC)) for _ in range(maxD)])
