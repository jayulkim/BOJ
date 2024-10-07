#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long double ary[100005] = { 0, };

int compare(const void* num1, const void* num2)
{
	long double a = *(long double*)num1;
	long double b = *(long double*)num2;
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
	long double num1 = 0;
	long double num2 = 0;
	scanf("%Lf %Lf", &num1, &num2);
	int num3 = num1;
	int num4 = num2;
	for (int i = 0; i < num1; i++)
	{
		scanf("%Lf", &ary[i]);
	}
	qsort(ary, num1, sizeof(long double), compare);
	long double sum = 0;
	for (int i = num2; i < num1 - num2; i++)
	{
		sum += ary[i];
	}
	printf("%.2Lf\n", sum / (num1 - 2 * num2) + 0.00000001);
	for (int i = 0; i < num2; i++)
	{
		sum += ary[num4];
	}
	for (int i = 0; i < num2; i++)
	{
		sum += ary[num3 - num4 - 1];
	}
	printf("%.2Lf", sum / (num1) + 0.00000001);
}