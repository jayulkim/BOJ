#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[1100005] = { 0, };
long long int ary1[110005] = { 0, };
int ary2[1100005] = { 0, };

int main(void)
{
    long long int num1 = 0;	long long int num2 = 0;

    for (int i = 2; i <= 1100000; i++)
    {
        if (ary[i] == 0)
        {
            for (int j = 2 * i; j <= 1100000; j += i)
            {
                ary[j] = 1;
            }
        }
    }

    int index = 0;

    for (long long int i = 2; i <= 1100000; i++)
    {
        if (ary[i] == 0)
        {
            ary1[index] = i;
            index++;
        }
    }

    scanf("%lld %lld", &num1, &num2);
    long long int count = num2 - num1 + 1;

    for (long long int i = 0; ary1[i] * ary1[i] <= num2; i++)
    {
        for (long long int j = (num1 / (ary1[i] * ary1[i])) * ary1[i] * ary1[i]; j <= num2; j += ary1[i] * ary1[i])
        {
            if (j >= num1)
            {
                ary2[j % 1000001] = 1;
            }
        }
    }

    for (int i = 0; i < 1000001; i++)
    {
        if (ary2[i] == 1)
        {
            count--;
        }
    }

    printf("%lld ", count);



}