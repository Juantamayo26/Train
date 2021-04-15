from random import seed, shuffle

seed(42)
input()
d, *dishes = input().split()
shuffle(dishes)
print(d, *dishes, sep="\n")
