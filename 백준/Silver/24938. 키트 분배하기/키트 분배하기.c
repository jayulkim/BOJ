#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
long long int ary[200001];
int main(void)
{
    long long int n = 0;
    scanf("%lld", &n);
    long long int sum = 0;
    for (int j = 0; j < n; j++)
    {
        scanf("%lld", &ary[j]);
        sum += ary[j];
    }
    sum /= n;
    long long int count = 0;
    for (int j = 0; j < n - 1; j++)
    {
        if (ary[j] < sum)
        {
            count += (sum - ary[j]);
            ary[j + 1] -= (sum - ary[j]);
        }
        else
        {
            count += (ary[j] - sum);
            ary[j + 1] += (ary[j] -sum);
        }
    }
    printf("%lld", count);
    return 0;
}