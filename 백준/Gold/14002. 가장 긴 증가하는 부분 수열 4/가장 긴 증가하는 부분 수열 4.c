#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[1005] = { 0, };
int dp[1005] = { 0, };
int dp1[1005] = { 0, };
int result[1005] = { 0, };

typedef struct info
{
	int stack[1005];
	int head;
}info;

info list[1005] = { 0, };

void push(info* list, int i, int num)
{
	list[i].stack[++list[i].head] = num;
}

int compare(const void* num1, const void* num2)
{
	return *(int*)num1 - *(int*)num2;
}

int main(void)
{
	for (int i = 0; i <= 1003; i++)
	{
		list[i].head = -1;
	}

	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 1; i <= num1; i++)
	{
		scanf("%d", &ary[i]);
	}
	
	for (int i = 1; i <= num1; i++)
	{
		int max = 0;
		int index = 0;
		for (int j = i - 1; j >= 1; j--)
		{
			if (ary[i] > ary[j])
			{
				if (max < dp[j])
				{
					max = dp[j];
					index = j;
				}
			}
		}
		for (int j = 0; j <= list[index].head; j++)
		{
			push(list, i, list[index].stack[j]);
		}
		push(list, i, ary[i]);
		dp[i] = dp[index] + 1;
	}
	int max = 0;
	int index1 = 0;
	for (int i = 1; i <= num1; i++)
	{
		if (dp[i] > max)
		{
			max = dp[i];
			index1 = i;
		}
	}
	printf("%d\n", max);
	for (int i = 0; i <= list[index1].head; i++)
	{
		printf("%d ", list[index1].stack[i]);
	}
}