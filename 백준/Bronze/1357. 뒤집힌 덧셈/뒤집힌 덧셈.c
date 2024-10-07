#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <math.h>

#include <stdlib.h>

#include <string.h>

#include <ctype.h>

int main(void)

{

    char num2[10] = {};

    char mun2[10] = {};

    char num3[10] = {};

    char mun3[10] = {};

    int ary1[10] = {0,};

    int index = 0;

    int result1 = 0;

    

    int count = 0;

    scanf("%s %s", num2, num3);

    

    int num1 = strlen(num2);

    int num4 = strlen(num3);

    for (int j = 0; j < num1; j++)

    {

        mun2[j] = num2[num1 - 1 - j];

    }

    for (int j = 0; j < num4; j++)

    {

        mun3[j] = num3[num4 - 1 - j];

    }

        

    result1 = atoi(mun3)+ atoi(mun2);

    while (result1 >= 1)

    {

        ary1[index] = result1 % 10;

        index++;

        result1 /= 10;

    }

    

    

    for (int j = 0; j < index; j++)

    {

        

        if (ary1[j] != 0)

        {

            break;

        }

        count++;

    }

    for (int j = count; j < index; j++)

    {

        printf("%d", ary1[j]);

    }

}