#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ary[20000] = { 0, };

int main(void)
{
	int num1;

	scanf("%d", &num1);

	int num2 = 0;

	scanf("%d", &num2);

	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary[i]);
	}

	int result = 0;

	for (int i = 0; i < num1 - 1; i++)
	{
		for (int j = 0; j < num1; j++)
		{
			if (j != i)
			{
				if (ary[i] != 0 && ary[j] != 0)
				{
					if (ary[i] + ary[j] == num2)
					{
						result++;
						ary[i] = 0;
						ary[j] = 0;
					}
				}
			}
			
		}
	}
	printf("%d\n", result);
	

}