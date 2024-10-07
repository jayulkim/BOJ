#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

int stack[200001];

int ary[200001];

int head = -1;

void push(int* stack, int num)

{

    stack[++head] = num;

}

int pop(int* stack)

{

    return stack[head--];

}

int top(int* stack)

{

    return stack[head];

}

int main(void)

{

    int n = 0;

    scanf("%d", &n);

    int count = n - 1;

    for(int j = 0; j < n; j++)

    {

        scanf("%d", &ary[j]);

    }

    for(int j = 0; j < n; j++)

    {

        if (head == -1)

        {

            push(stack, ary[j]);

        }

        else

        {

            while(head != -1 && top(stack) < ary[j])

            {

                if (head > 0)

                {

                    count++;

                }

                pop(stack);

            }

            push(stack, ary[j]);

        }

    }

    printf("%d", count);

}