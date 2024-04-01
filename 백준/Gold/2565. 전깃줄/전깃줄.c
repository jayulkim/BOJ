#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct info
{
	int left;
	int right;
}info;

info list[105];

int dp[105] = { 0, };

int compare(const void* num1, const void* num2)
{
	info* a = (info*)num1;
	info* b = (info*)num2;
	if (a->left > b->left)
	{
		return 1;
	}
	else if (a->left < b->left)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
int compare1(const void* num1, const void* num2)
{
	return *(int*)num1 - *(int*)num2;
}

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 1; i <= num1; i++)
	{
		scanf("%d %d", &list[i].left, &list[i].right);
	}
	qsort(list, num1 + 1, sizeof(info), compare);
	
	for (int i = 1; i <= num1; i++)
	{
		int index = 0;
		int max = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (list[i].right > list[j].right)
			{
				if (max < dp[j])
				{
					max = dp[j];
					index = j;
				}
			}
		}
		dp[i] = dp[index] + 1;
	}
	
	qsort(dp, num1 +1, sizeof(int), compare1);
	printf("%d", num1 - dp[num1]);

}