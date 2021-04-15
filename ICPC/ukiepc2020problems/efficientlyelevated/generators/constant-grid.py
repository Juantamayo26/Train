#!/usr/bin/env python3
import sys

print(sys.argv[1], sys.argv[2])
for _ in range(int(sys.argv[1])):
    print(*([sys.argv[3]]*int(sys.argv[2])))
