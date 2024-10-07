a, b = map(int, input().split())

c = 1
d = 1
if (b > 50):
    b = (a - b)

for i in range(a-b + 1, a + 1, 1):
    c *= i


for i in range(1, b + 1):
    d *= i



print(c// d)