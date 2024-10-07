#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;

    scanf("%d", &num1);
    scanf("%d", &num2);
    scanf("%d", &num3);

   
    if (num2 >= num3)
    {
        printf("%d\n", -1);
    }
    else
    {
        printf("%d\n", num1 / (num3 - num2) + 1);
    }

}
