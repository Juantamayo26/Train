def step(k):
    if k == 10: return 9 # Nasty edge case
    s = str(k)
    l = s[:(len(s)+1)//2]
    r = ''.join(reversed(l[:len(s)//2]))
    if int(l+r) <= k: return int(l+r)
    l = str(int(l)-1)
    r = ''.join(reversed(l[:len(s)//2]))
    assert int(l+r) <= k
    return int(l+r)

n=int(input())
a=[]
while n and len(a) < 11:
    a.append(step(n))
    n -= a[-1]
print(len(a), *a, sep='\n')
