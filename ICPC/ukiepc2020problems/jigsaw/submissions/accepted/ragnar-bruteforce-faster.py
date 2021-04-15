c, e, m = map(int, input().split())
if c == 4 and e%2==0:
    w = 1
    while True:
        w += 1
        if (w-2)*(w-2) > m: break;

        h = (e-2*(w-2))//2+2
        if m==(w-2)*(h-2):
            print(w,h)
            exit(0)
print('impossible')
