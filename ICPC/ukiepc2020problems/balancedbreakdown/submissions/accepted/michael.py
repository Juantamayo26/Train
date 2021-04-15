m = int(input())

def rem_pal(m):
    if m==0:
        return []
    ml = list(str(m))
    nl = ['0']*len(ml)
    for i in range(len(ml)//2+len(ml)%2):
        nl[i] = ml[i]
        nl[len(ml)-1-i] = ml[i]
        if int("".join(nl))>int(m):
            if i==0 and ml[i]=='1':
                nl = list(str(m-1))
            else:
                nl[i]           = str(int(ml[i])-1)
                nl[len(ml)-1-i] = str(int(ml[i])-1)
                for j in range(i+1, len(ml)//2+len(ml)%2):
                    nl[j] = '9'
                    nl[len(ml)-1-j] = '9'
            break
    return [int("".join(nl))]+rem_pal(m-int("".join(nl)))

res = rem_pal(m)
print(len(res))
[print(x) for x in res]