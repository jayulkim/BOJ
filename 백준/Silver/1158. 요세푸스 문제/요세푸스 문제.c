#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int queue[25000010] = { 0, };
int headup = -1;
int headdown = 0;

int empty(int* queue)
{
	if (headup + 1 == headdown)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(int* queue, int num)
{
	queue[++headup] = num;
}

int pop(int* queue)
{
	return queue[headdown++];
}

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);

	for (int i = 1; i <= num1; i++)
	{
		push(queue, i);
	}
	printf("<");
	while (empty(queue) == 0)
	{
		for (int i = 0; i < num2 - 1; i++)
		{
			push(queue, pop(queue));
		}
		if (headup - headdown == 0)
		{
			printf("%d>", pop(queue));
		}
		else
		{
			printf("%d, ", pop(queue));
		}	
	}
}

