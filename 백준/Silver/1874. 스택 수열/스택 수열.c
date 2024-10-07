#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int stack[100005] = { 0, };
int stack1[100005] = { 0, };

int ary[100005] = { 0, };
int head = -1;

int empty(int* stack)
{
	if (head == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

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
	int num1 = 0;
	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary[i]);
	}
	int index = 0;
	int count = 1;

	int index1 = 0;
	int count1 = 1;

	int count2 = 0;
	while (index < num1)
	{
		if (empty(stack) == 0)
		{
			if (ary[index] == top(stack))
			{
				pop(stack);
				//printf("-\n");
				index++;
			}
			else
			{
				push(stack, count);
				//printf("+\n");
				count++;
			}
		}
		else
		{
			push(stack, count);
			//printf("+\n");
			count++;

		}
	//	printf("%d\n", count);
		if (count >1 +  num1)
		{
			count2++;
			printf("NO");
			break;
		}
	}
	if (count2 == 0)
	{
		while (index1 < num1)
		{
			if (empty(stack1) == 0)
			{
				if (ary[index1] == top(stack1))
				{
					pop(stack1);
					printf("-\n");
					index1++;
				}
				else
				{
					push(stack1, count1);
					printf("+\n");
					count1++;
				}
			}
			else
			{
				push(stack1, count1);
				printf("+\n");
				count1++;

			}
		}
	}

}