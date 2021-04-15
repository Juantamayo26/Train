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
m = [0] * (k+1)
minl = 0
fixl = None
for i in range(k):
    if fixed[i]:
        targetl = -m[i]
        if fixl and fixl != targetl: impossible()
        fixl = targetl

    # s[i] - m[i] + m[i+1] = t[i]
    m[i+1] = t[i] - s[i] + m[i]
    minl = max(minl, -m[i+1])
if fixl is not None:
    if fixl < minl: impossible()
    minl = fixl

print(sum(m) + (k+1)*minl)
