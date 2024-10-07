#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int ary[1025][1025] = { 0, };
int sum[1025][1025] = { 0, };



int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;

	scanf("%d %d", &num1, &num2);

	for (int i = 1; i <= num1; i++)
	{
		for (int j = 1; j <= num2; j++)
		{
			scanf("%d", &ary[j][i]);
			sum[j][i] = ary[j][i] + sum[j - 1][i] + sum[j][i - 1] - sum[j - 1][i - 1];
		}
	}
	scanf("%d", &num3);

	for (int i = 0; i < num3; i++)
	{
		int r1 = 0;
		int c1 = 0;

		int r2 = 0;
		int c2 = 0;

		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		int result = 0;

		result = sum[c2][r2] - sum[c2][r1 - 1] - sum[c1 - 1][r2] + sum[c1 - 1][r1 - 1];
		printf("%d\n", result);
	}

}

