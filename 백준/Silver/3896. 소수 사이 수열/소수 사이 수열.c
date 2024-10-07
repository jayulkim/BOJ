#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[1299710] = { 0, };

int ary1[1299710] = { 0, };

int main(void)
{
	for (int i = 2; i <= 1299709; i++)
	{
		ary[i] = i;
	}
	int index = 0;
	for (int i = 2; i <= 1299709; i++)
	{
		if (ary[i] != 0)
		{
			for (int j = i * 2; j <= 1299709; j += i)
			{

				ary[j] = 0;
			}
			ary1[index] = ary[i];
			index++;
		}
	}
	for (int i = 2; i < 100000; i++)
	{
		//printf("%d\n", ary1[i]);
	}
	int num1 = 0;
	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		int num2 = 0;
		scanf("%d", &num2);

		if (ary[num2] == num2)
		{
			printf("0\n");
		}
		else
		{
			int len = 0;
			for (int i = 0; i < 100000; i++)
			{
				if (ary1[i] < num2 && ary1[i + 1] > num2)
				{
					len = ary1[i + 1] - ary1[i];
					break;
				}
			}
			printf("%d\n", len);
		}

	}
	
	
}