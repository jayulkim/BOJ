#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num1 = 0;
    int num2 = 0;
    scanf("%d", &num1);
    scanf("%d", &num2);

    for (int i = 0; i < num1; i++)
    {
        for (int j = 0; j < num2; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}