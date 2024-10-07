#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[5000005] = { 0, };

int ary1[1000005] = { 0, };

int ary2[331] = { 0, };

int main(void)
{
	for (int i = 2; i * i <= 5000000; i++)
	{
		if (ary[i] == 0)
		{
			for (int j = i * i; j <= 5000000; j+= i)
			{
				ary[j] = 1;
			}
		}
		
	}
	int index1 = 0;
	for (int i = 2; i * i <= 5000000; i++)
	{
		if (ary[i] == 0)
		{
			ary2[index1] = i;
			//printf("%d ", ary2[index1]);
			index1++;
		}
	}
	//printf("%d\n", ary2[330]);
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary1[i]);
	}
	for (int i = 0; i < num1; i++)
	{
		int index = 0;
		while (ary1[i] > 1)
		{
			if (ary1[i] % ary2[index] == 0)
			{
				printf("%d ", ary2[index]);
				ary1[i] /= ary2[index];
			}
			else
			{
				index++;
				if (index == 331)
				{
					printf("%d ", ary1[i]);
					break;
				}
			}
		}
		printf("\n");
	}

}