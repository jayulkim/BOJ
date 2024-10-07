#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <math.h>

#include <stdlib.h>

#include <string.h>

#include <ctype.h>

int main(void)

{

    char num1[10];

    

    gets(num1);

    

    for (int i = 0; i < atoi(num1); i++)

    {

        char num2[10] = {};

        char mun2[10] = {};

        int ary1[10] = {0,};

        int result = 0;

        int index = 0;

        gets(num2);

        

        int num3 = strlen(num2);

        

        for (int j = 0; j < num3; j++)

        {

            mun2[j] = num2[num3 - 1 - j];

        }

        

        

        result = atoi(num2) + atoi(mun2);

        

        while (result >= 1)

        {

            ary1[index] = result % 10;

            index++;

            

            result /= 10;

        }

        

        int count = 0;

        for (int j = 0; j <= index/ 2; j++)

        {

            

            if (ary1[j] != ary1[index - j - 1])

            {

                count++;

                break;

            }

        }

        if (count == 0)

        {

            printf("YES\n");

        }

        else if (count != 0)

        {

            printf("NO\n");

        }

        

    }

   

}