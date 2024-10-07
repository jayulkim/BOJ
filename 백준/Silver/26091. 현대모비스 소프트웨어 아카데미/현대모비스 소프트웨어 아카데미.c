#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int ary[1000005] = { 0, };

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
	qsort(ary, num1, sizeof(int), compare);

	int count = 0;
	int start = 0;
	int end = num1 - 1;
	while (start < end)
	{
		if (ary[end] + ary[start] >= num2)
		{
			count++;
			end--;
			start++;
		}
		else
		{
			start++;
		}
	}
	printf("%d\n", count);

}