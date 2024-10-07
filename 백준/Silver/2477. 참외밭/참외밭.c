#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct info
{
	int forward;
	long long int len;
}info;
info list[10];

long long int ary[10] = { 0, };

int compare(const void* num1, const void* num2)
{
	long long int a = *(long long int*)num1;
	long long int b = *(long long int*)num2;
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
	long long int num1 = 0;
	scanf("%lld", &num1);
	int count = 0;
	long long int minus = 0;
	for (int i = 0; i < 6; i++)
	{
		scanf("%d %lld", &list[i].forward, &list[i].len);
		ary[list[i].forward] += list[i].len;
	}
	for (int i = 6; i < 12; i++)
	{
		list[i].forward = list[i - 6].forward;
		list[i].len = list[i - 6].len;
	}
	for (int i = 0; i < 6; i++)
	{
		if (list[i].forward == list[i + 2].forward && list[i+1].forward == list[i + 3].forward)
		{
			minus = list[i + 1].len * list[i + 2].len;
		}
	}

	
	qsort(ary, 5, sizeof(long long int), compare);
	long long int plus = ary[2] * ary[3];
	
	printf("%lld\n", num1 * (plus - minus));

}


