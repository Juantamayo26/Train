# This combines all dishes into one big set
s = set(x for x in input().split()[1:] for _ in range(int(input())))
print(len(s), *s, sep='\n')
