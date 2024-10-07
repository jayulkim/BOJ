#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ary[5005][5005] = { 0, };
int sum[5005][5005] = { 0, };

int main(void)
{
	int num1 = 0;
	
	scanf("%d", &num1);

	for (int i = 1; i <= num1; i++)
	{
		for (int j = 1; j <= num1; j++)
		{
			scanf("%d", &ary[i][j]);
			sum[i][j] = ary[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}

	int num2 = 0;
	scanf("%d", &num2);
	for (int i = 0; i < num2; i++)
	{
		int x1 = 0;
		int y1 = 0;
		int x2 = 0;
		int y2 = 0;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		int result = sum[x2-1][y2-1] - sum[x1][y2-1] - sum[x2-1][y1] + sum[x1][y1];

		int result1 = sum[x2 ][y2 ] - sum[x1-1][y2] - sum[x2 ][y1-1] + sum[x1-1][y1-1];
		printf("%d\n",2 *  result - result1 );
	}


	
}