a = int(input())
b = int(input())
h = 0
for i in range(1, b + 1) :
    c, d = map(int, input().split())
    e = c * d
    h += e
if h == a :
    print("Yes")
else:
    print("No")

