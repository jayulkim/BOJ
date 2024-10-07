#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ary[1000005] = { 0, };
int sum[1000005] = { 0, };

int compare(const void* num1, const void* num2)
{
	int a = *(int*)num1;
	int b = *(int*)num2;
	if (a > b)
	{
		return 1;
	}
	else if (a < b)
	{
		return -1;
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
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary[i]);
	}
	sum[0] = ary[0];
	for (int i = 1; i < num2; i++)
	{
		sum[i] = sum[i - 1] + ary[i];
	}
	for (int i = num2; i < num1; i++)
	{
		sum[i] = sum[i - 1] - ary[i - num2] + ary[i];
	}
	qsort(sum, num1, sizeof(int), compare);
	int count = 0;
	for (int i = 0; i < num1; i++)
	{
		//printf("%d ", sum[i]);
		if (sum[i] == sum[num1 - 1])
		{
			count++;
		}
	}
	if (sum[num1 - 1] == 0)
	{
		printf("SAD\n");
	}
	else
	{
		printf("%d\n", sum[num1 - 1]);
		printf("%d\n", count);
	}
	

}

