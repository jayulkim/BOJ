a, b = map(int, input().split())
c = []
d = []
e = []
for i in range(1, a + 1) :
    c.append(input().split())   
for z in range(1, a + 1) :
    d.append(input().split()) 
for h in range(0, a):
    for x in range(0, b):
        e.append(int(c[h][x]) + int(d[h][x]))
for o in range(0, a * b, b):
    k = e[o:b + o]
    print(*k)
    