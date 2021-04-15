#!/usr/bin/env python3



print("1000 999 100 1000000")
print(" ".join(str(x) for x in range(100, 1001, 100) for _ in range(10)))
print("1 2 1000000")
for v in range(101, 902, 100):
    print("1 {} 1000000".format(v))
for i in range(2, 100):
    print("{} {} 1000000".format(i, i+1))
for i in range(101, 902, 100):
    for j in range(i, i+99):
        print("{} {} 1000000".format(j, j+1))

