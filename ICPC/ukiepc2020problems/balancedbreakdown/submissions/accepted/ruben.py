
def is_p(n):
    return str(n) == str(n)[::-1]

def next_p(n):
    if is_p(n):
        return n
    d = len(str(n))
    if d%2 == 0:
        d = (d // 2)
        first_half = str(n)[:d]
        k = int(first_half + first_half[::-1])
        if k < n:
            return k
        else:
            first_half = str(int(first_half)-1)
            k = int(first_half + first_half[::-1])
            return k
    else:
        d = (d // 2) + 1
        first_half = str(n)[:d]
        k = int(first_half + first_half[:-1][::-1])
        if k < n:
            return k
        else:
            first_half = str(int(first_half)-1)
            k = int(first_half + first_half[:-1][::-1])
            return k

n = int(input())

N = 100000

pre = [[] for _ in range(N)]
pal = [x for x in range(N) if is_p(x)]


# precompute for numbers up to N
for p in pal:
    pre[p] = [p]
for p1 in pal:
    for p2 in pal:
        if p1 + p2 >= N:
            break
        if len(pre[p1+p2]) == 0:
            pre[p1+p2] = [p1, p2]

for num in range(N-1, 0, -1):
    if len(pre[num]) == 0:
        for p in pal:
            if len(pre[num-p]) == 2:
                pre[num] = pre[num-p] + [p]
                break 
        
res = []

while n >= N:
    np = next_p(n)
    res.append(np)
    n -= np

if n != 0:
    res += pre[n]

print(len(res))
for p in res:
    print(p)




