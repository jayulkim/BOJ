#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <math.h>

#include <stdlib.h>

#include <string.h>

#include <ctype.h>

int main(void)

{

    int num1 = 0;

    int num2 = 0;

    while (scanf("%d %d", &num1, &num2) != EOF)

    {

        int result = num1;

        

        while (num1 >= num2)

        {

            result += num1 / num2;

            

            num1 = (num1 / num2) + (num1 % num2);

        }

        printf("%d\n", result);

        

    }

}