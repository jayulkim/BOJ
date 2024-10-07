#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <math.h>

#include <stdlib.h>

#include <string.h>

#include <ctype.h>

int compare(const void*num1, const void*num2)

{

    int a = *(int*)num1;

    int b = *(int*)num2;

    if (a > b)

    {

        return 1;

    } 

    else if (a < b)

    {

        return -1;

    } 

    else

    {

        return 0;

    }

}

int main(void)

{

    int num1 = 0;

    int ary1[30000] = {0,};

    int ary2[30000] = {0,};

    

    scanf("%d", &num1);

    

    for (int j = 0; j < num1; j++)

    {

        scanf("%d", &ary1[j]);

    }

    int num3 = 0;

    

    int index2 = 0;

    int index = 0;

    for (int j = 0; j < num1; j++)

    {

      

        if(ary1[j] >= num3)

        {

            num3 = ary1[j];

            

            for (int n = j+1; n < num1; n++)

            {

            

                if (ary1[j] <= ary1[n])

                {

                     

                     break;

                }

                else

                {

                    ary2[j]++;

                }

            }    

        }

        

    } 

    qsort(ary2, num1, sizeof(int), compare);

    printf("%d", ary2[num1 - 1]);

    

}