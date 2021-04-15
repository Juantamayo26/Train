n,p = map(int, input().split())

cur = 0
last = None
delta = 0
scores = []
for i in range(n):
    t = int(input())
    if i==0:
        if t>0:
            cur = p
    elif t<last:
        cur -=1
    last = t
    scores.append(cur)
if cur != 0:
    print("ambiguous")
else:
    [print(x) for x in scores]