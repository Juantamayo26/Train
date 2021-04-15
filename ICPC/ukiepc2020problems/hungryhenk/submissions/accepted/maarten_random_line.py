from random import seed, randint

seed(4242)
n = int(input())
for _ in range(randint(0, n - 1)):
    input()
print("\n".join(input().split()))
