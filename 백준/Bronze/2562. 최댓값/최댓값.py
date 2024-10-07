a = []
for i in range(1, 10) :
    a.append(int(input()))
print(max(a))
print(a.index(max(a)) + 1)