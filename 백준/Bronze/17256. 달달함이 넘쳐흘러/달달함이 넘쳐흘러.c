#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int num = 0;
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int num4 = 0;
    int num5 = 0;

    scanf("%d %d %d", &num, &num1, &num2);
    scanf("%d %d %d", &num3, &num4, &num5);
   
    printf("%d %d %d", num3 - num2, num4 / num1, num5 - num);
   
}