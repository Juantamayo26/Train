s = [input().split()[-1] for _ in range(int(input()))]
print(len(s), *s, sep='\n')
