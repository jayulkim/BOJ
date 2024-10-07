def n ():
    a, b = map(int, input().split())
    print(a + b)
    return a + b
try:
    while True:
        n()
except:
    print("")