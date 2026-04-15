#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[5005];

int deque[50000005];
int headdown = 25000000;
int headup = 24999999;

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
	return deque[headup--];
}

int popdown(int* deque)
{
	return deque[headdown++];
}

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	scanf("%d %d %d", &num1, &num2, &num3);
	for (int i = 1; i <= num1; i++)
	{
		pushup(deque, i);
	}
	int num4 = 0;
	int num5 = num3;
	while (empty(deque) == 0)
	{
		if (num3 > 0)
		{
			num4 = 0;
			for (int i = 0; i < num2 - 1; i++)
			{
				if (empty(deque) == 0)
				{
					pushup(deque, deque[headdown]);
					popdown(deque);
				}	
			}
			printf("%d\n",deque[headdown]);
			popdown(deque);
			num3--;
		}
		else if (num3 == 0)
		{
			for (int i = 0; i < num2 - 1; i++)
			{
				if (empty(deque) == 0)
				{
					pushdown(deque, deque[headup]);
					popup(deque);
				}
			}
			printf("%d\n",deque[headup]);
			popup(deque);
			num4++;
		}
		if (num4 == num5)
		{
			num3 = num5;
		}

	}
}