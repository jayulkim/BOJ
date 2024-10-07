#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

char str[105];

double stack[105];

double ary[205] = {0,};

double ary1[205] = {0,};

int head = -1;

void push(double* stack, double num)

{

    stack[++head] = num;

}

double pop(double* stack)

{

    return stack[head--];

}

int main(void)

{

  //  printf("%d", 'A');

	int num1 = 0;    scanf("%d",&num1);

    scanf("%s",str);

    int num2 = strlen(str);

    int num3 = 0;

    

    for(int j = 0; j<num1;j++)

    {

        scanf("%lf", &ary1[j+65]);

    }

    for(int j = 0; j < num2; j++)

    {

        if (str[j] == '*')

        {

            double num4 = pop(stack);

            double num5 = pop(stack);

            push(stack, num5 *num4);

        }

        else if(str[j] == '+')

        {

            double num4 = pop(stack);

            double num5 = pop(stack);

            push(stack, num5 +num4);

        }

        else if (str[j] == '-')

        {

            double num4 = pop(stack);

            double num5 = pop(stack);

            push(stack, num5 -num4);

        }

        else if (str[j] == '/')

        {

            double num4 = pop(stack);

            double num5 = pop(stack);

            push(stack, num5 /num4);

        }

        else

        {

            push(stack, ary1[str[j]]);

        }

    }

    printf("%.2lf", stack[0]);

}