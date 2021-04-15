import sys

c,ef,m = [int(x) for x in sys.stdin.readlines()[0].split()]
e=ef//2
if c!=4:
    print("impossible")
    exit()

for i in range(e+1):
    if m==i*(e-i):
        print(i+2, e-i+2)
        exit()
    elif m<i*(e-i):
        break
print("impossible")