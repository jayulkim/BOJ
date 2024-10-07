#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int stack[1000001] = { 0, };

int head = -1;

int empty()
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

void push(int num1)
{
	stack[++head] = num1;
}

int pop()
{
	if (empty() == 1)
	{
		return -1;
	}
	else
	{
		return stack[head--];
	}

}

int size()
{
	return head + 1;
}


int top()
{
	if (empty() == 1)
	{
		return -1;
	}
	else
	{
		return stack[head];
	}

}


int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		int num2 = 0;
		scanf("%d", &num2);

		if (num2 == 1)
		{
			int num3 = 0;
			scanf("%d", &num3);
			push(num3);
		}
		else if (num2 == 2)
		{
			printf("%d\n", pop());
		}
		else if (num2 == 3)
		{
			printf("%d\n", size());
		}
		else if (num2 == 4)
		{
			printf("%d\n", empty());
		}
		else if (num2 == 5)
		{
			printf("%d\n", top());
		}
	}


}
