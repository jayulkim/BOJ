#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long int dp[1200][200] = { 0, };

int prime[1200] = { 0, };
int ary[500] = { 0, };
int main(void)
{
    for (int i = 2; i < 1200; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = 2 * i; j < 1200; j += i)
            {
                prime[j] = 1;
            }
        }
    }
    int index = 0;
    for (int i = 2; i < 1200; i++)
    {
        if (prime[i] == 0)
        {
            ary[index] = i;
            index++;
        }
    }
    dp[0][0] = 1;
    for (int i = 0; i < index; i++)
    {
    //    dp[ary[i]][1] = 1;
    }
    for (int i = 0; i < index; i++)
    {  
        for (int j = 1200; j >= ary[i]; j--)
        {
            for (int k = 1; k < 15; k++)
            {
                dp[j][k] += dp[j-ary[i]][k - 1];
            }
        }
    }


    int num1 = 0;
    scanf("%d", &num1);
    for (int i = 0; i < num1; i++)
    {
        int num2 = 0;
        int num3 = 0;
        scanf("%d %d", &num2, &num3);
        printf("%lld\n", dp[num2][num3]);
    }
}