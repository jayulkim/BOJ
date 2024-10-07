#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num1 = 0;
    scanf("%d", &num1);

    if (num1 % 7 == 2)
    {
        printf("1");
    }
    else
    {
        printf("0");
    }
}