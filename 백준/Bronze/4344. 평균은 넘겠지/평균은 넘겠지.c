#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int num1 = 0;

    scanf("%d", &num1);

    for (int i = 0; i < num1; i++)
    {
        int num2 = 0;
        int ary1[1100] = { 0, };

        int sum = 0;
        int count = 0;
        scanf("%d", &num2);
        for (int j = 0; j < num2; j++)
        {
            scanf("%d", &ary1[j]);
            sum += ary1[j];
        }
        int avr = sum / num2;
        for (int j = 0; j < num2; j++)
        {
            if (ary1[j] > avr)
            {
                count++;
            }
        }
        double result = (double)count / (double)num2 * 100;
        printf("%.3lf%\n", result);

    }

}
