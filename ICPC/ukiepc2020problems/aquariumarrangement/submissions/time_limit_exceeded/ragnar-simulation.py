R = lambda: list(map(int, input().split()))
[n, k], s, t = R(), R(), R()

ans = 0

def impossible():
    print('impossible')
    exit(0)

def move_left(i):
    global ans
    if i == 0:
        if s[i] <= 2: impossible()
        s[i] -= 1
        ans += 1
    else:
        if s[i-1] >= s[i] - 3:
            move_left(i-1)
        else:
            s[i-1] += 1
            s[i] -= 1
            ans += 1
            assert s[i] - s[i-1] >= 2

def move_right(i):
    global ans
    if i == k-1:
        if s[i] >= n-1: impossible()
        s[i] += 1
        ans += 1
    else:
        if s[i] >= s[i+1] - 3:
            move_right(i+1)
        else:
            s[i] += 1
            s[i+1] -= 1
            ans += 1
            assert s[i+1] - s[i] >= 2

while s != t:
    for i in range(k):
        while s[i] > t[i]: move_left(i)
        while s[i] < t[i]: move_right(i)

print(ans)
