#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[100005] = { 0, };
int ary1[1000005] = { 0, };

int result[1000005] = { 0, };

int ary2[100005] = { 0, };
int ary3[100005] = { 0, };
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
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary[i]);
		ary1[ary[i]]++;
		ary2[i] = ary[i];
	}
	int index = 0;
	qsort(ary2, num1, sizeof(int), compare);
	for (int i = 0; i < num1; i++)
	{
		if (ary2[i] != ary2[i + 1])
		{
			ary3[index] = ary2[i];
			//printf("%d ", ary3[index]);
			index++;
		}
	}

	for (int i = 0; i < index; i++)
	{
		for (int j = ary3[i]; j <= ary3[index - 1]; j += ary3[i])
		{
			result[j] += ary1[ary3[i]];
		}
	}
	for (int i = 0; i < num1; i++)
	{
		printf("%d\n", result[ary[i]] - 1);
	}
}