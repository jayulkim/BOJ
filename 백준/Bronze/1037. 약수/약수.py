a = int(input())
b = list(map(int, input().split()))
if len(b) == 1:
    print(int(b[0]) ** 2)
if len(b) >= 2:
    print(int(max(b)) * int(min(b)))