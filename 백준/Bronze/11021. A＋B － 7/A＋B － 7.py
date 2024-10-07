v = int(input())
c = 1
for i in range(1, v + 1):
    a, b = map(int, input().split())
    print(f"Case #{c}:",a + b)
    c += 1