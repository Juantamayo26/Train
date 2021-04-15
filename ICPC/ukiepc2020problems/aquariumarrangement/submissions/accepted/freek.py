R = lambda: list(map(int, input().split()))
[n, k], p, d = R(), R(), R()

ss = [0]
mini, total = 0, 0
for i in range(1, k + 1):
    s = ss[i - 1] + d[i - 1] - p[i - 1]
    mini = min(mini, s)
    total += s
    ss.append(s)
for i in range(k + 1):
    ss[i] -= mini
total -= mini * (k + 1)
t, i = 0, 0
impossible = False
while t < total:
    if i == 0:
        if ss[i] == 0 or p[i] < 3:
            i += 1
        else:
            s = min(ss[i], p[i] - 2)
            p[i] -= s
            ss[i] -= s
            t += s
            i += 1
    elif i < k:
        if ss[i] == 0 or p[i] - p[i - 1] < 4:
            i += 1
        else:
            s = min(ss[i], (p[i] - p[i - 1] - 2) >> 1)
            p[i - 1] += s
            p[i] -= s
            ss[i] -= s
            t += s
            i -= 1
    else:
        if ss[i] == 0 or n - p[i - 1] < 2:
            print("impossible")
            impossible = True
            break
        else:
            s = min(ss[i], n - p[i - 1] - 1)
            p[i - 1] += s
            ss[i] -= s
            t += s
            i -= 1
if not impossible:
    print(total)
