a = {}
b = 0
c = 1
a[0] = 0
a[1] = 2
for i in range(2, 100001):
    d = b + c
    a[d] = i
    b = c
    c = d
e = int(input())
for i in range(int(e)):
    f = int(input())
    print(a[f])