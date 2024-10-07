#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[3] = { 0, };

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
}

int main(void)
{
	scanf("%d %d %d", &ary[0], &ary[1], &ary[2]);
	qsort(ary, 3, sizeof(int), compare);
	printf("%d %d %d", ary[0], ary[1], ary[2]);
}