#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int que[2000005] = { 0, };
int front = 0;
int back = -1;
int empty()
{
	if (back + 1 == front)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(int* que, int num)
{
	que[++back] = num;
}
int pop(int* que)
{
	return que[front++];
}

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);
	for (int i = 1; i <= num1; i++)
	{
		push(que, i);
	}
	printf("<");
	while (num1--)
	{
		for (int i = 0; i < num2 - 1; i++)
		{
			push(que, pop(que));
		}
		if (front == back)
		{
			printf("%d>", pop(que));
		}
		else
		{
			printf("%d, ", pop(que));
		}
	}
}
