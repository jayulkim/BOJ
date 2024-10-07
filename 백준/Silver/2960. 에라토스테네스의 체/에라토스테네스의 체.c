#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[1005] = { 0, };

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);
	for (int i = 2; i <= num1; i++)
	{
		if (ary[i] == 0)
		{
			for (int j = i; j <= num1; j += i)
			{
				if (ary[j] == 0)
				{
					ary[j] = 1;
					num2--;
				}
				if (num2 == 0)
				{
					printf("%d", j);
					return 0;
				}
			}
		}
	}
}
