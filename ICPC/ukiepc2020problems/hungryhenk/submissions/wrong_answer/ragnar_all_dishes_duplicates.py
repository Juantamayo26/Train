s = [x for _ in range(int(input())) for x in input().split()[1:]]
print(len(s), *s, sep='\n')
