#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
char str[10];
long long int ary[3] = { 0, };

int main(void)
{
    int num1 = 0;
    int num2 = 0;


    for (int j = 0; j < 3; j++)
    {
        gets(str);
        if (strcmp(str, "black") == 0)
        {
            ary[j] = 0;
            if (j == 2)
            {
                ary[j] = 1;
            }

        }
        if (strcmp(str, "brown") == 0)
        {
            ary[j] = 1;
            if (j == 2)
            {
                ary[j] = 10;
            }
        }
        if (strcmp(str, "red") == 0)
        {
            ary[j] = 2;
            if (j == 2)
            {
                ary[j] = 100;
            }
        }
        if (strcmp(str, "orange") == 0)
        {
            ary[j] = 3;
            if (j == 2)
            {
                ary[j] = 1000;
            }
        }
        if (strcmp(str, "yellow") == 0)
        {
            ary[j] = 4;
            if (j == 2)
            {
                ary[j] = 10000;
            }
        }
        if (strcmp(str, "green") == 0)
        {
            ary[j] = 5;
            if (j == 2)
            {
                ary[j] = 100000;
            }
        }
        if (strcmp(str, "blue") == 0)
        {
            ary[j] = 6;
            if (j == 2)
            {
                ary[j] = 1000000;
            }

        }
        if (strcmp(str, "violet") == 0)
        {
            ary[j] = 7;
            if (j == 2)
            {
                ary[j] = 10000000;
            }
        }
        if (strcmp(str, "grey") == 0)
        {
            ary[j] = 8;
            if (j == 2)
            {
                ary[j] = 100000000;
            }
        }
        if (strcmp(str, "white") == 0)
        {
            ary[j] = 9;
            if (j == 2)
            {
                ary[j] = 1000000000;
            }
        }
    }
    printf("%lld", ((ary[0] * 10) + ary[1]) * ary[2]);


   
}