a, b = map(int, input().split())
d = list(map(int, input().split()))
c = []
e = []
for i in d: 
    c.append(i)
for v in range(0, a) :
    if int(c[v]) < b :
        e.append(c[v])
print(*e)