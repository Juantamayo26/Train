#!/usr/bin/python3
c,e,m = map(int, input().split(' '))

x = c + e + m
y = e // 2 + 4
# solve: wh = x, w+h = y

D = y*y - 4*x

if c != 4 or e % 2 == 1 or D < 0:
	print("impossible")
	exit(0)

Dsq = int(D**0.4999999)
while Dsq*Dsq < D:
	Dsq += 1

w = (y+Dsq)//2
h = y - w

# accepted: if Dsq*Dsq == D and (y+Dsq) % 2 == 0 and w >= 2 and h >= 2:
# wrong:    if                  (y+Dsq) % 2 == 0 and w >= 2 and h >= 2:

if w < h:
	exit(1)

if (y+Dsq) % 2 == 0 and w >= 2 and h >= 2:
	print(w, h)
else:
	print("impossible")
