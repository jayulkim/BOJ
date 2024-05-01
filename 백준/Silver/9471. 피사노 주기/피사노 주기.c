#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Pow(int x, int r)
{
	int result = 1;
	while (r > 0)
	{
		if (r % 2 == 1)
		{
			result *= x;
		}
		x *= x;
		r /= 2;
	}
	return result;
}

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0;i < num1;i++)
	{
		int number = 0;
		int m = 0;
		scanf("%d %d", &number, &m);

		int pre = 1;
		int pre1 = 1;
		int count = 0;
		while (1)
		{
			int temp = (pre + pre1) % m;
			pre1 = pre;
			pre = temp;
			if (pre1 == 1 && pre == 1)
			{
				break;
			}
			count++;
		}
		printf("%d %d\n", number, count + 1);
	}
}