import sys
n = int(sys.stdin.readline().strip())
v = list(map(int, sys.stdin.readline().split()))
m = int(sys.stdin.readline().strip())
dp = [[0] * 51 for i in range(51)]
for i in range(1, 51):
    for j in range(1, m + 1):
        Max = 0
        for k in range(0, n):
            if (j - v[k] >= 0):
                Max = max(Max, dp[i - 1][j - v[k]] * 10 + k)
        dp[i][j] = max(dp[i][j], Max)
Max = 0
for i in range(1, 51):
    for j in range(1, m + 1):
        Max = max(Max, dp[i][j])
print(Max)