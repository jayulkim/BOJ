#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct info
{
	long long int score;
	int x;
}info;
info list[100005];

long long int ary[5000005] = { 0, };

int compare(const void* num1, const void* num2)
{
	info* a = (info*)num1;
	info* b = (info*)num2;
	if (a->x > b->x)
	{
		return 1;
	}
	else if (a->x < b->x)
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
		scanf("%d %d", &list[i].score, &list[i].x);
		ary[list[i].x] = list[i].score;
	}
	qsort(list, num1, sizeof(info), compare);

	for (int i =  0; i <= list[num1 - 1].x; i++)
	{
	//	printf("%d ", ary[i]);
	}
	long long sum = 0;
	for (int i = 0; i < 1 + 2 * num2; i++)
	{
		sum += ary[i];
	}
//	printf("%lld\n", sum);
	long long max = sum;
	for (int i = 0; i <= list[num1 - 1].x - 2 * num2 + 1; i++)
	{
		sum -= ary[i];
		sum += ary[i + 1 + 2 * num2];
		if (sum > max)
		{
			max = sum;
		}
	}
	printf("%lld", max);
	
}