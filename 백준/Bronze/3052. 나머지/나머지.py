b = []
for i in range(10):
    a = int(input())
    b.append(a % 42)
b = set(b)
print(len(b))
