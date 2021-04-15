#!/usr/bin/python3
import os, sys

if len(sys.argv) < 4:
	print("usage:", __file__, " [WIDTH] [HEIGHT] [TESTCASE_NAME]")
	exit(0)

w = int(sys.argv[1])
h = int(sys.argv[2])
name = sys.argv[3]

c = 4
e = 2*(w-2) + 2*(h-2)
m = (w-2) * (h-2)

dirname = os.path.abspath(os.path.dirname(os.path.realpath(__file__)) + "/../data/secret/" + name)

print("Making file with w =", w, "and h =", h)
with open(dirname + ".in", "w") as inputFile:
	print(c, e, m, file=inputFile)

with open(dirname + ".ans", "w") as answerFile:
	print(w, h, file=answerFile)
