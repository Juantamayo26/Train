#!/usr/bin/env python3

n = int(input())
print('yes' if sum(map(int, input().split())) % 3 == 0 else 'no')
