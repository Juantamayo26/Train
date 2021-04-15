powers_of_ten = [10**i for i in range(20)]

def as_pal(N):
    res = []
    max_size = len(str(N))
    while N:
        if N < 10:
            res.append(N)
            break
        if N in powers_of_ten:
            res.append(N-1)
            res.append(1)
            break

        exp = max(i for i in range(max_size) if 10**i < N)
        pal = 0

        for i in range((exp + 1)//2):
            term = 10**(exp - i) + 10**i
            pr = N // term
            pal += pr*term
            N -= pr*term

        if exp % 2 == 0:
            term = 10**(exp//2)
            pr = N // term
            pal += pr*term
            N -= pr*term

        res.append(pal)
    return res

N = int(input())
res = as_pal(N)
assert sum(res) == N
print(len(res))
print(*res, sep="\n")
