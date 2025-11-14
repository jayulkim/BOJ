import sys
input = sys.stdin.readline
import heapq
sys.setrecursionlimit(10000)
n = int(input())
result = 0
Map = {}
for i in range(n):
    str = input().strip()
    for j in range(len(str) - 1, -1, -1):
        if (str[j].isdigit()):
            result += (ord(str[j]) - ord('0')) * pow(36, len(str) - 1 - j)
            Map[ord(str[j]) - ord('0')] = Map.get(ord(str[j]) - ord('0'), 0) + 36 ** (len(str) - 1 - j)
        else:
            result += (ord(str[j]) - 55) * pow(36, len(str) - 1 - j)
            Map[ord(str[j]) - 55] = Map.get(ord(str[j]) - 55, 0) + 36 ** (len(str) - 1 - j)
m = int(input())
pq = []
for i in range(36):
    if (i in Map):
        heapq.heappush(pq, (-(35 * Map[i] - i * Map[i]), i))
count = 0
while (pq):
    if (count == m):
        break
    a, b = heapq.heappop(pq)
    result -= a
    count += 1
s = ""
if (not result):
    print(0)
    exit(0)
while (result > 0):
    if (result % 36 >= 10):
        s += chr(int(result % 36) + 55)
    else:
        s += chr(int(result % 36) + ord('0'))
    result //= 36
print(s[::-1])