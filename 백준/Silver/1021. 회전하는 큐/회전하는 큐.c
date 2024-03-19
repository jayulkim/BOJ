#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[55];

int deque[100005];
int headdown = 1000;
int headup = 999;

int empty(int* deque)
{
	if (headdown - 1 == headup)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void pushup(int* deque, int num)
{
	deque[++headup] = num;
}

void pushdown(int* deque, int num)
{
	deque[--headdown] = num;
}

int popup(int* deque)
{
	if (empty(deque) == 0)
	{
		return deque[headup--];
	}
	else
	{
		return 0;
	}
}

int popdown(int* deque)
{
	if (empty(deque) == 0)
	{
		return deque[headdown++];
	}
	else
	{
		return 0;
	}
}

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);
	for (int i = 1; i <= num1; i++)
	{
		pushup(deque, i);
	}
	for (int i = 0; i < num2; i++)
	{
		scanf("%d", &ary[i]);
	}
	int result = 0;
	for (int i = 0; i < num2; i++)
	{
		int index = 0;
		for (int j = headdown; j <= headup; j++)
		{
			if (deque[j] == ary[i])
			{
				index = j;
				break;
			}
		}
		if (headup - index + 1 >= index - headdown)
		{
			int count = index - headdown;
			for (int j = 0; j < count; j++)
			{
				result++;
				pushup(deque, popdown(deque));
			}
			popdown(deque);
		}
		else
		{
			int count = headup - index + 1;
			for (int j = 0; j < count; j++)
			{
				result++;
				pushdown(deque, popup(deque));
			}
			popdown(deque);
		}


		for (int j = headdown; j <= headup; j++)
		{
			//	printf("%d ", deque[j]);
		}
		//	printf("\n");
		//	printf("%d\n", result);
	}
	printf("%d\n", result);
	return 0;
}