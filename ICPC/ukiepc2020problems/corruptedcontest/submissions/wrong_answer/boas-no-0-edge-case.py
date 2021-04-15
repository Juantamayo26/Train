import sys

first_line = sys.stdin.readline().split()
n = int(first_line[0])
p = int(first_line[1])

scores = []

for i in range(n):
    scores.append(int(sys.stdin.readline()))

scores.reverse()

solved = []


cur_solved = 0
cur_score = 0
for s in scores:
    if s == 0:
        solved.append(0)
        continue

    if s > cur_score:
        cur_solved += 1
    cur_score = s
    solved.append(cur_solved)

if cur_solved < p:
    print('ambiguous')
    exit()

solved.reverse()
for s in solved:
    print(s)
