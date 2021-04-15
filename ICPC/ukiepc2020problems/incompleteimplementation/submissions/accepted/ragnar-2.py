n = int(input())
v = list(map(lambda x: int(x)-1, input().split()))
iv = [0 for _ in range(n)]
for i in range(n): iv[v[i]] = i
print(3)
for i in range(3):
    j, s = i*n//4, set()
    while len(s) < n//2:
        s.add(j+1)
        if len(s) < n//2: s.add(iv[j]+1)
        j += 1
    print(*s)
    l = sorted([v[p-1] for p in sorted(s)])
    for j, p in enumerate(sorted(s)): v[p-1] = l[j]
    for j in range(n): iv[v[j]] = j
