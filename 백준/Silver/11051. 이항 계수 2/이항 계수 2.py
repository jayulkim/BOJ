a, b = map(int, input().split())

c = a
d = b
e = (a - 1)
f = (b - 1)

if (b == 0):
    print(1)
else:
    for i in range(b - 1):
        c *= e
        e -= 1
        d *= f
        f -= 1

    print((c // d) % 10007)

