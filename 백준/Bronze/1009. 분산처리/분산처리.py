a = int(input())
for i in range(a):
    b, c = map(int, input().split())
    if b == 1:
        print(b)
    elif b % 10 != 0 and c % 4 == 1:
        print(b % 10)
    elif b % 10 != 0 and c % 4 == 2:
        print(b ** 2 % 10)
    elif b % 10 != 0 and c % 4 == 3:
        print(b ** 3 % 10)
    elif b % 10 != 0 and c % 4 == 0:
        print(b ** 4 % 10)
    elif b % 10 == 0:
        print("10")
