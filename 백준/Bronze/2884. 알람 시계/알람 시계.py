a, b = map(int, input().split())
if a != 0 and b >= 45 :
    print(a,b - 45)
elif a != 0 and 0 < b < 45 :
    print(a - 1,abs(60 - (abs(b - 45))))
elif a == 0 and b == 45 :
    print("0 0")
elif a == 0 and b < 45 :
    print("23",abs(60 - (abs(b - 45))))
elif a == 0 and b > 45 :
    print(a,b - 45)