#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

long long int ary[12] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };

long long int mod(long long int x, long long int y, long long int num)
{
    long long int result = 0;
    x %= num;
    y %= num;
    while (y > 0)
    {
        if (y % 2 == 1)
        {
            result += x;
            result %= num;
        }
        x *= 2;
        x %= num;
        y /= 2;
    }
    return result;
}

long long int gcd(long long int num1, long long int num2)
{
    long long int temp = num1 % num2;
    while (temp != 0)
    {
        num1 = num2;
        num2 = temp;
        temp = num1 % num2;
    }
    return num2;
}

long long int Pow(long long int prime, long long int d, long long int num)
{
    if (d == 0)
    {
        return 1LL;
    }
    long long int count = (Pow(prime, d / 2, num) % num);
    count %= num;
    if (d % 2 == 0)
    {
        return mod(count % num, count % num, num) % num;
    }
    else
    {
        return mod(mod((prime % num), (count % num), num), (count % num), num) % num;
    }
}

int millerlabin(long long int prime, long long int num)
{
    if (num < 2)
    {
        return 1;
    }
    if (num == 2)
    {
        return 0;
    }
    if (num % prime == 0)
    {
        return 0;
    }
    long long int num1 = num - 1;
    while (1)
    {
        long long int temp = Pow(prime, num1, num) % num;
        if (temp == num - 1)
        {
            return 0;
        }
        else
        {
            if (num1 % 2 == 0)
            {
                num1 /= 2;
            }
            else
            {
                if (temp == 1 || temp == num - 1)
                {
                    return 0;
                }
                else
                {
                    return 1;
                }
            }
        }
    }
}

int isprime(long long int num)
{
    for (int i = 0; i < 12; i++)
    {
        if (millerlabin(ary[i], num) == 1)
        {
            return 1;
        }
    }
    return 0;
}

long long int Random(long long int x, long long int c, long long int num)
{
    return (mod(x % num, x % num, num) + c % num) % num;
}

long long int pollardrho(long long int num)
{
    if (num % 2 == 0)
    {
        return 2;
    }
    if (isprime(num) == 0)
    {
        return num;
    }
    long long int x = (rand() % (num - 2)) + 1;
    long long int c = (rand() % 3) * 2 - 1;
    long long int y = x;
    long long int d = 1;
    while (gcd(d, num) == 1)
    {
        x = Random(x, c, num) % num;
        y = Random(y, c, num) % num;
        y = Random(y, c, num) % num;
        d = llabs(x - y);
        if (gcd(d, num) == num)
        {
            return pollardrho(gcd(d, num));
        }
    }
    if (isprime(gcd(d, num)) == 0)
    {
        return gcd(d, num);
    }
    else
    {
        return pollardrho(gcd(d, num));
    }
}

long long int ary1[65] = { 0, };
int index = 1;

void oilerpi(long long int number)
{
    while (number > 1)
    {
        long long int number1 = pollardrho(number);
        ary1[index] = number1;
        index++;
        number /= number1;
    }
}

int compare(const void* num1, const void* num2)
{
    long long int a = *(long long int*)num1;
    long long int b = *(long long int*)num2;
    if (a > b)
    {
        return 1;
    }
    else if (a < b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    srand(time(NULL));
    long long int num1 = 0;
    long long int result = 1;
    scanf("%lld", &num1);
    oilerpi(num1);
    qsort(ary1, index, sizeof(long long int), compare);
    for (int i = 1; i < index; i++)
    {
        if (ary1[i] != 0)
        {
            if (ary1[i] != ary1[i - 1])
            {
                result *= (ary1[i] - 1);
            }
            else
            {
                result *= ary1[i];
            }
        }
    }
    printf("%lld", result);
}