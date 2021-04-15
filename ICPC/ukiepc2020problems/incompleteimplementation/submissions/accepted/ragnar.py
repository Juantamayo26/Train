n = int(input())
v = list(map(lambda x: int(x)-1, input().split()))
iv = [0 for _ in range(n)]
for i in range(n): iv[v[i]] = i
print(3)
for i in range(3):
    s = set()
    for j in range(n//4):
        s.add(i*n//4 + j)
        s.add(iv[i*n//4 + j])
    for j in reversed(range(n)):
        if len(s) == n//2: break;
        s.add(j)
    print(*(p+1 for p in s))
    l = sorted([v[p] for p in sorted(s)])
    for j, p in enumerate(sorted(s)): v[p] = l[j]
    for j in range(n): iv[v[j]] = j
