#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long double ary[300005] = { 0, };

typedef struct info
{
	long double x;
	long double y;
	long double W;
}info;

info list[100005];
typedef struct Sum
{
	long double distanceW;
	long double W;
}Sum;
Sum sum[100005];
int compare(const void* num1, const void* num2)
{
	info* a = (info*)num1;
	info* b = (info*)num2;
	if ((a->x) * (a->x) + (a->y) * (a->y) > (b->x) * (b->x) + (b->y) * (b->y))
	{
		return 1;
	}
	else if ((a->x) * (a->x) + (a->y) * (a->y) < (b->x) * (b->x) + (b->y) * (b->y))
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
int compare1(const void* num1, const void* num2)
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
	int num1 = 0;
	long double A = 0;
	scanf("%d %Lf", &num1, &A);
	for (int i = 0; i < num1; i++)
	{
		scanf("%Lf %Lf %Lf", &list[i].x, &list[i].y, &list[i].W);
	}
	qsort(list, num1, sizeof(info), compare);
	sum[0].W = list[0].W;
	sum[0].distanceW = sqrt(list[0].x * list[0].x + list[0].y * list[0].y) * list[0].W;
	int index = 0;
	for (int i = 1; i < num1; i++)
	{
		sum[i].W = sum[i - 1].W + list[i].W;
		sum[i].distanceW = sum[i - 1].distanceW + sqrt(list[i].x * list[i].x + list[i].y * list[i].y) * list[i].W;
	}

	for (int i = 0; i < num1; i++)
	{
		if (i != num1 - 1)
		{
			ary[index] = sqrt(list[i].x * list[i].x + list[i].y * list[i].y) * sum[i].W - A * (list[i].x * list[i].x + list[i].y * list[i].y) - sum[i].distanceW;
			index++;
			if (sum[i].W / (2 * A) > sqrt(list[i].x * list[i].x + list[i].y * list[i].y) && sum[i].W / (2*A) < sqrt(list[i + 1].x * list[i + 1].x + list[i + 1].y * list[i + 1].y))
			{
				ary[index] = (sum[i].W * sum[i].W) / (2 * A)  - A * (sum[i].W / (2 * A)) * (sum[i].W / (2 * A)) - sum[i].distanceW;
				index++;
			}
		}
		else
		{
			ary[index] = sqrt(list[i].x * list[i].x + list[i].y * list[i].y) * sum[i].W - A * (list[i].x * list[i].x + list[i].y * list[i].y) - sum[i].distanceW;
			index++;
			if (sum[i].W / (2 * A) > sqrt(list[i].x * list[i].x + list[i].y * list[i].y))
			{
				ary[index] = (sum[i].W / (2 * A)) * sum[i].W - A * (sum[i].W / (2 * A)) * (sum[i].W / (2 * A)) - sum[i].distanceW;
				index++;
			}
		}
	}
	qsort(ary, index, sizeof(long double), compare1);
	if (ary[index - 1] <= 0)
	{
		printf("0");
	}
	else
	{
		printf("%Lf\n", ary[index - 1]);
	}
}