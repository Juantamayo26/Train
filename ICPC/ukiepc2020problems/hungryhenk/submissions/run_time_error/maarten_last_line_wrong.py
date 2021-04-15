n = int(input())
for _ in range(n):
    input()
# This throws and EOFError because we're out of input
print("\n".join(input().split()))
