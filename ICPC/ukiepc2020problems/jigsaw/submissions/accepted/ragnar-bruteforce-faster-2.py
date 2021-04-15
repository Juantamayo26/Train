c, e, m = map(int, input().split())
if c == 4 and e%2==0:
    w = -1
    m2 = m*2
    while True:
        w += 1
        if w*w > m: break;
        if m2==w*(e-2*w):
            print(w+2,(e-2*w)//2+2)
            exit(0)
print('impossible')
