import itertools
n, p = map(int, input().split())
ts = [int(input()) for _ in range(n)] + [0]
ds = [int(x>y) for x, y in zip(ts, ts[1:])]
if sum(ds) != p:
    print('ambiguous')
    exit(0)
print(*[p-x for x in itertools.accumulate([0] + ds[:-1])], sep='\n')
