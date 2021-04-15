def step(k):
    if k < 10: return k
    s = str(k)
    p = s[0] + '0'*(len(s)-2) + s[0]
    if int(p) <= k: return int(p)
    if s[0] == '1': return int('9'*(len(s)-1))
    return int(str(int(s[0])-1) + '0'*(len(s)-2) + str(int(s[0])-1))

n=int(input())
a=[]
while n:
    a.append(step(n))
    n -= a[-1]
print(len(a), *a, sep='\n')
