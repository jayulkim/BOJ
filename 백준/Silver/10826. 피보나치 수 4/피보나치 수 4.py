a = [0, 1]

for j in range(2, 10001):

    a.append(a[j - 1] + a[j - 2])

b = input()

print(a[int(b)])