N = input()
max_size = len(N)
N = int(N)
res = []

N_orig = N

while N:
    if N < 10:
        res.append(N)
        break
    if str(N)[0] == "1" and all(x == "0" for x in str(N)[1:]):
        res.append(N-1)
        res.append(1)
        break

    exp = max(i for i in range(max_size) if 10**i < N)
    term = 10**exp + 1
    pr = min(9, N // term)
    pal = pr*term
    N -= pr*term
    res.append(pal)

assert sum(res) == N_orig
print(len(res))
print(*res, sep="\n")
