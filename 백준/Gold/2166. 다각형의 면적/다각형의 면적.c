#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct pos
{
	double x;
	double y;
}pos;

pos list[100000];


int main(void)
{
	int num1 = 0;

	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		scanf("%lf %lf", &list[i].x, &list[i].y);
	}

	double result1 = 0;
	double result2 = 0;
	for (int i = 0; i < num1 - 1; i++)
	{
		result1 += (list[i].x * list[i + 1].y);
	}
	for (int i = 0; i < num1 - 1; i++)
	{
		result2 += (list[i].y * list[i + 1].x);
	}
	result1 += (list[num1 - 1].x * list[0].y);
	result2 += (list[0].x * list[num1 - 1].y);

	printf("%.1lf", fabs((result1 - result2)) / 2);

}