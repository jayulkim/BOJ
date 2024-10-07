#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ary[200005] = { 0, };

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);

	int count = 0;
	int count1 = 0;
	for (int i = 0; i < num2; i++)
	{
		int num3 = 0;
		scanf("%d", &num3);
		
		for (int j = 0; j < num3; j++)
		{
			scanf("%d", &ary[j]);
			
		}
		for (int j = 0; j < num3; j++)
		{
			if (ary[j] < ary[j + 1])
			{
				count++;

			}

		}
		
		if (count != 0)
		{
			count1++;
			
		}
		for (int j = 0; j < num3; j++)
		{
			ary[j] = 0;
		}
	}
	if (count1 == 0)
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}
}