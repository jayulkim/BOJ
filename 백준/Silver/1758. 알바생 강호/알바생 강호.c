#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ary[200002] = { 0, };

int compare(const void* num1, const void* num2)
{
	int a = *(int*)num1;
	int b = *(int*)num2;
	if (a > b)
	{
		return -1;
	}
	else if (a < b)
	{
		return 1;
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

	long long int sum = 0;
	for (int i = 0; i < num1; i++)
	{
		scanf("%lld", &ary[i]);
	}
	qsort(ary, num1, sizeof(int), compare);


	for (int i = 0; i < num1; i++)
	{
		
		if (ary[i] - (i) > 0)
		{
			sum += ary[i] - (i);
		}
	}
	printf("%lld\n", sum);
}