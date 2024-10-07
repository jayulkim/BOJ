#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct map
{
	int ary[101][101];
}map;
map arymul(map x, map y, int n, int num)
{
	map result = { {{0}} };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				result.ary[i][j] += ((x.ary[i][k] % num) * (y.ary[k][j] % num)) % num;
			}	
		}
	}
	return result;
}
map arypow(map x, int p, int n, int num)
{
	map result = { {{0}} };
	for (int i = 0; i < n; i++)
	{
		result.ary[i][i] = 1;
	}
	while (p > 0)
	{
		if (p % 2 == 1)
		{
			result = arymul(result, x, n, num);
		}
		x = arymul(x, x, n, num);
		p /= 2;
	}
	return result;
}
int main(void)
{
	map result = { {{0,}} };
	while (1)
	{
		int n = 0, m = 0, p = 0;
		scanf("%d %d %d", &n, &m, &p);
		if (n == 0 && m == 0 && p == 0)
		{
			break;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &result.ary[i][j]);
			}
		}
		result = arypow(result, p, n, m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("%d ", result.ary[i][j] % m);
			}
			printf("\n");
		}
		printf("\n");
	}
}