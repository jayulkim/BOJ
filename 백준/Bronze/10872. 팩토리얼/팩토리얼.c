#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int num = 0;
    int result = 1;
    scanf("%d", &num);

    for (int i = 1; i <= num; i++)
    {
        result *= i;
    }
    printf("%d", result);
   
}