import sys
n = int(input())
m = set()
strings = [list(map(str, input().split())) for x in range(n)]
yes = True
x = 1
for i in strings:
  if(i[0] == "->"):
    m.add(i[1])
  else:
    for j in range(len(i)):
      if(i[j] == "->"):
        m.add(i[j+1])
        break
      if(i[j] not in m):
        print(x)
        sys.exit()
  x+=1

print("correct")
