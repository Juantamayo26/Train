import sys

line = [int(x) for x in sys.stdin.readline().split()]
n = line[0]
p = line[1]

scores = []

for i in range(n):
    scores.append(int(sys.stdin.readline()))

# special case: scores without 0 = num problems solved
if len([x for x in scores if x > 0]) == p:
    c = p
    for s in scores:
        if s == 0:
            print(0)
        else:
            print(c)
            c -= 1
    exit()


scores.reverse()


max_solved = 0
solved = []

cur_score = 0
for score in scores:
    if score > cur_score:
        max_solved += 1
    solved.append(max_solved)
    cur_score = score

solved.reverse()

if max_solved == p:
    for s in solved:
        print(s)
else:
    print("ambiguous")
