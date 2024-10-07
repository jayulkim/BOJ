#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ary1[200002] = { 0, };

int ary2[200002] = { 0, };

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
	

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &ary1[i]);
	}
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &ary2[i]);
	}
	qsort(ary1, 10, sizeof(int), compare);
	qsort(ary2, 10, sizeof(int), compare);
	printf("%d %d", ary1[9] + ary1[8] + ary1[7], ary2[9] + ary2[8] + ary2[7]);
}