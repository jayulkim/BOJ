#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int ary[60] = { 0, };

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
	}

	int num2 = 0;
	scanf("%d", &num2);

	qsort(ary, num1, sizeof(int), compare);

	int index = 0;
	int count = 0;
	for (int i = 0; i < num1; i++)
	{
		if (ary[i] == num2)
		{
			printf("0\n");
			count++;
			break;
		}
		else if (ary[i] > num2)
		{
			index = i;
			break;
		}
	}
	if (count == 0)
	{
		printf("%d\n", (num2 - ary[index - 1] - 1) * (ary[index] - num2) + ary[index] - num2 - 1);
	}

}



