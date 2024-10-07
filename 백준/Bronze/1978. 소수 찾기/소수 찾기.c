#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int ary1[100000] = { 0, };

int main(void)
{
	int num1 = 0;
	int count = 0;

	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary1[i]);
	}
	for (int j = 0; j < num1; j++)
	{
		if (ary1[j] > 2)
		{
			for (int i = 2; i < ary1[j]; i++)
			{
				if (ary1[j] % i == 0)
				{
					ary1[j] = 0;
				}

			}

		}
		
		if (ary1[j] == 1)
		{
			ary1[j] = 0;
		}
		
	}
	for (int i = 0; i < num1; i++)
	{
		if (ary1[i] != 0)
		{
			count += 1;
		}
	}
	printf("%d", count);
	

}