input()
d, *dishes = input().split()
print(d, *dishes[::-1], sep="\n")
