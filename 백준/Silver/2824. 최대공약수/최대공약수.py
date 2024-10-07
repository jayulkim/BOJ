def gcd(a, b):
    temp = a % b
    while (temp > 0):
        a = b
        b = temp
        temp = a % b
    return b

a = int(input())
b = 1
list1 = []

list1 = list(map(int, input().split()))
for i in range(a):
   b *= list1[i]

c = int(input())
d = 1
list2 = []

list2 = list(map(int, input().split()))
for i in range(c):
    d *= list2[i]

if (gcd(b,d) >= 1000000000):
    if (gcd(b,d) % 1000000000 < 10):
        print("00000000"+str(gcd(b,d) % 1000000000))

    elif (gcd(b,d) % 1000000000 < 100):
        print("0000000"+str(gcd(b,d) % 1000000000))

    elif (gcd(b,d) % 1000000000 < 1000):
        print("000000"+str(gcd(b,d) % 1000000000))

    elif(gcd(b,d) % 1000000000 < 10000):
        print("00000"+str(gcd(b,d) % 1000000000))

    elif(gcd(b,d) % 1000000000 < 100000):
        print("0000"+str(gcd(b,d) % 1000000000))

    elif(gcd(b,d) % 1000000000 < 1000000):
        print("000"+str(gcd(b,d) % 1000000000))

    elif(gcd(b,d) % 1000000000 < 10000000):
        print("00"+str(gcd(b,d) % 1000000000))

    elif(gcd(b,d) % 1000000000 < 100000000):
        print("0"+str(gcd(b,d) % 1000000000))

    else:
        print(gcd(b,d) % 1000000000)

else:
    print(gcd(b,d) % 1000000000)
