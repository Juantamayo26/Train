# @EXPECTED_RESULTS@: WRONG_ANSWER, TIME_LIMIT_EXCEEDED
import sys

mutations = [(0,-1),(0,1),(-1,0),(1,0)]

lines = sys.stdin.readlines()
my,mx = [int(x) for x in lines[0].split()]

mtrx = [[int(x) if int(x)!=1 else 0 for x in line.split()] for line in lines[1:]]
towers = 0
for yi,y in enumerate(mtrx):
    for xi,x in enumerate(y):
        if x==0:
            continue
        sup = 0
        small = False
        for l,t in mutations:
            try:
                if x > mtrx[yi+t][xi+l]:
                    try:
                        if yi-1<0:
                            raise IndexError
                        cmpv = x>mtrx[yi-1][xi]
                    except IndexError as e:
                        cmpv = True
                    try:
                        if xi-1<0:
                            raise IndexError
                        cmph = x>mtrx[yi][xi-1]
                    except IndexError as e:
                        cmph = True
                    if cmph and cmpv:
                        sup+=1
                elif x < mtrx[yi+t][xi+l]:
                    small=True
            except IndexError as e:
                continue
        if not small and sup>0:
            towers += 1
print(towers)
