R = lambda: list(map(int, input().split()))
[n, k], s, t = R(), R(), R()

ans = 0

def impossible():
    print('impossible')
    exit(0)

fixed = [False] * k
for i in range(k-1):
    if t[i+1] == t[i]+1:
        fixed[i] = fixed[i+1] = True
        if s[i] != t[i] or s[i+1] != t[i+1]: impossible()

# border checks
if s[0] > 1 and t[0] == 1: impossible()
if s[0] < n and t[0] == n: impossible()


# The number of times we move the leftmost piranha to the left.
# TODO: there must be a more reasonable upper bound for this?
for l in range(n*n):
    # s[i]: number of moves just left of i
    def try_l():
        m = [0] * (k+1)
        m[0] = l
        for i in range(k):
            if fixed[i] and m[i] != 0: return

            # s[i] - m[i] + m[i+1] = t[i]
            m[i+1] = t[i] - s[i] + m[i]
            if m[i+1] < 0: return
        print(sum(m))
        exit(0)

    try_l()

impossible()
