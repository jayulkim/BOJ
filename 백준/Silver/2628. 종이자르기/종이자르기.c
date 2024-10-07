#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ary1[200002] = { 0, };

int ary2[200002] = { 0, };

int result1[200002] = { 0, };

int result2[200002] = { 0, };

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
	ary1[0] = 0;
	ary2[0] = 0;
	int num1 = 0;
	int num2 = 0;

	scanf("%d %d", &num1, &num2);

	int num3 = 0;
	scanf("%d", &num3);
	int index1 = 1;
	int index2 = 1;
	for (int i = 0; i < num3; i++)
	{
		int num4 = 0;
		int num5 = 0;
		scanf("%d %d", &num4, &num5);

		if (num4 == 0)
		{
			ary1[index1] = num5;
			index1++;
		}
		else if (num4 == 1)
		{
			ary2[index2] = num5;
			index2++;
		}

	}
	ary1[index1] = num2;

	ary2[index2] = num1;
	qsort(ary1, index1 + 1, sizeof(int), compare);
	qsort(ary2, index2 + 1, sizeof(int), compare);
	int index3 = 0;
	for (int i = 0; i < index1; i++)
	{
		result1[index3] = ary1[i + 1] - ary1[i];
		index3++;
	}
	int index4 = 0;
	for (int i = 0; i < index2; i++)
	{
		result2[index4] = ary2[i + 1] - ary2[i];
		index4++;
	}
	qsort(result1, index3, sizeof(int), compare);
	qsort(result2, index4, sizeof(int), compare);
	printf("%d\n", result1[index3 - 1] * result2[index4 - 1]);
	
}