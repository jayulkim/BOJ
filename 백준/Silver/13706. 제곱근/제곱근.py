a = int(input())
b = 1
c = 0
d = a
while (b <= a):
    c = (a + b) // 2
    if (c * c < d):
        b = c
    else:
        a = c
        if (c * c == d):
            print(c)
            break