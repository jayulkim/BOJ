import sys
a = int(input())
d = []
b = list(map(int, sys.stdin.readline().split()))
b.sort()
for j in range(0, a):
    c = int(b[j])/int(b[-1])*100
    d.append(c)
print(sum(d) / a)