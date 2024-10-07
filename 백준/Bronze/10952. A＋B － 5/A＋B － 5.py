try :
    while True :
        a, b = map(int, input().split())
        if a == b == 0:
            print("")
            break
        else:
            print(a + b)
except :
    print("")