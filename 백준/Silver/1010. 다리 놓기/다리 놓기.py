a = int(input())
def d (x):
    k = 1
    for n in range(1, x + 1):
        k *= n
    return k
for i in range(1, a + 1):
    b, c = map(int, input().split())
    print(round(d(c) / d(b) / d(c - b)))