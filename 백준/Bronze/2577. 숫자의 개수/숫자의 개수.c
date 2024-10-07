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
    
    int ary1[10] = { 0, };
    int num4 = num1 * num2 * num3;
    while (num4 >= 1)
    {
        ary1[(num4 % 10)]++;
        num4 /= 10;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", ary1[i]);
    }

}
