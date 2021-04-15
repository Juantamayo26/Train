#!/usr/bin/env python3
import sys
import random
random.seed(sys.argv[1])
n = int(sys.argv[2])
p = int(sys.argv[3])
t = int(sys.argv[4])
withzeros = bool(int(sys.argv[5]))
scoreboard = []
for i in range(n):
	pp=random.randint(not withzeros,p)
	if pp > 0:
		scoreboard.append([-pp, random.randint(1, t)])
	else:
		scoreboard.append([0,0])

scoreboard=sorted(scoreboard)

print(str.format("{} {}", n, p))
for i in range(n):
    print(str.format("{}", scoreboard[i][1]))
