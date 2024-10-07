#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

int ary[9999999] = {0,};

int result[9999999] ={0,};

int stack[15] ={0,};

int head = -1;

void push (int *stack ,int num)

{

    stack[++head] = num;

}

int main(void)

{

    for (int j = 2; j <= 9989899; j++)

    {

        if(ary[j] == 0)

        {

            for( int k = 2* j; k <=9989899; k+=j)

            {

                ary[k] = 1;

            }

        }

    }

    

    for (int j = 2; j <= 9989899; j++)

    {

        if (ary[j] == 0)

        {

            int num1 = j;

            while (num1 >= 1)

            {

                push (stack, num1 % 10);

                num1 /= 10;

            }

            int count = 0;

            for(int k = 0; k <= head/2; k++)

            {

                if (stack[k] != stack[head - k])

                {

                    count++;

                    break;

                }

            }

            if (count == 0)

            {

                result[j] = 1;

            }

            head = -1;

        }

    }

    int num2 = 0;

    int num3 = 0;

    scanf("%d %d", &num2, &num3);

    for(int j = num2; j <= num3; j++)

    {

        if (result[j] == 1)

        {

            printf("%d\n", j);

        }    

        if ( j > 9989899)

        {

                printf("-1\n");

                return 0;

        }

    }

   

    printf("-1\n");

}