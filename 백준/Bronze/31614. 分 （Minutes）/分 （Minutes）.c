#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num1 = 0;
    int num2 = 0;
    scanf("%d", &num1);
    scanf("%d", &num2);
    printf("%d", num1 * 60 + num2);
}