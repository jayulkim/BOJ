import sys
n = int(sys.stdin.readline())
for i in range(n):
    num = int(sys.stdin.readline())
    start = 1
    end = num
    mid = 0
    Max = 0
    while (start <= end):
        mid = (start + end) // 2
        if (mid % 3 == 2):
            if ((mid + 1) // 3 + 2 * (mid // 3) + mid * (mid + 1) // 2 <= num):
                start = mid + 1
                Max = max(Max, mid + 1)
            else:
                end = mid - 1
        elif (mid % 3 == 1):
            if (2 * (mid // 3) + mid // 3 + mid * (mid + 1) // 2 <= num):
                start = mid + 1
                Max = max(Max, mid + 1)
            else:
                end = mid - 1
        elif (mid % 3 == 0):
            if (2 * (mid - 1) // 3 + mid // 3 + mid * (mid + 1) // 2 <= num):
                start = mid + 1
                Max = max(Max, mid + 1)
            else:
                end = mid - 1
    print(Max)