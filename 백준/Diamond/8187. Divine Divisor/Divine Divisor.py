import random
from collections import defaultdict
import sys
ary = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]
def gcd(a, b):
    temp = a % b
    while (temp > 0):
        a = b
        b = temp
        temp = a % b
    return b
def powmod(x, y, num):
    result = 1
    while y > 0:
        if y % 2:
            result *= (x % num)
            result %= num
        x *= (x % num)
        x %= num
        y //= 2
    return result
def Random(x, c, num):
    return (((x * x) % num) + c) % num
def millerlabin(x, a):
    if x == 1:
        return False
    if x == 2 or x == a:
        return True
    num = x - 1
    while True:
        temp = powmod(a, num, x)
        if temp == x - 1:
            return True
        if num % 2 == 0:
            num //= 2
        else:
            return temp == x - 1 or temp == 1
def isprime(x):
    for i in ary:
        if (millerlabin(x, i) == False):
            return False
    return True
def pollardrho(x):
    if x % 2 == 0:
        return 2
    if isprime(x):
        return x
    a = random.randint(1, x - 2)
    b = a
    c = random.randint(0, 2) * 2 - 1
    d = 1
    while gcd(d, x) == 1:
        a = Random(a, c, x)
        b = Random(b, c, x)
        b = Random(b, c, x)
        d = abs(a - b)
        if gcd(d, x) == x:
            return pollardrho(gcd(d, x))
    if isprime(gcd(d, x)) == False:
        return pollardrho(gcd(d, x))
    return gcd(d, x)
n = int(sys.stdin.readline())
num = list(map(int, sys.stdin.readline().split()))
Map = {}
for i in num:
    while i > 1:
        temp = pollardrho(i)
        i //= temp
        if temp in Map:
            Map[temp] += 1
        else:
            Map[temp] = 1
Max = 0
for i in Map.keys():
    Max = max(Max, Map[i])
temp = 0
for i in Map.values():
    if (i == Max):
        temp += 1
print(Max)
print(pow(2, temp) - 1)