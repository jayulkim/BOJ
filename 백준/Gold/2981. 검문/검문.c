#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[105] = { 0, };

int compare(const void* num1, const void* num2)
{
	return *(int*)num1 - *(int*)num2;
}
int ary1[105] = { 0, };
int result1[10000005] = { 0, };
int gcd(int num1, int num2)
{
	int temp = num1 % num2;
	while (temp > 0)
	{
		num1 = num2;
		num2 = temp;
		temp = num1 % num2;
	}
	return num2;
}

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary[i]);
	}
	qsort(ary, num1, sizeof(int), compare);
	for (int i = 1; i < num1; i++)
	{
		ary1[i] = ary[i] - ary[i - 1];
	}
	qsort(ary1, num1, sizeof(int), compare);
	
	int result = ary1[1];
	for (int i = 1; i < num1 - 1; i++)
	{
		result = gcd(result, ary1[i + 1]);
	}
//	printf("%d\n", result);
	int index = 0;
	for (int i = 1; i*i<= result; i++)
	{
		if (result % i == 0)
		{
			result1[index] = i;
			index++;
			result1[index] = result / i;
			index++;
		}
	}
	qsort(result1, index, sizeof(int), compare);
	for (int i = 1; i < index; i++)
	{
		if (result1[i] != result1[i + 1])
		{
			printf("%d ", result1[i]);
		}
	}
}