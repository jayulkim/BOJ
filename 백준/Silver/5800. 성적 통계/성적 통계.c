#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>

int ary[51] = { 0, };

int compare(const void* num1, const void* num2)
{
	int a = *(int*)num1;
	int b = *(int*)num2;
	if (a > b)
	{
		return -1;
	}
	else if (a < b)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		int num2 = 0;
		scanf("%d", &num2);

		for (int k = 0; k < num2; k++)
		{
			scanf("%d", &ary[k]);
			//printf("%d\n", ary[k]);
		}

		qsort(ary, num2, sizeof(int), compare);

		
		int num3 = 0;
		for (int k = 0; k < num2 -1; k++)
		{
			if (num3 <= ary[k] - ary[k + 1])
			{
				num3 = ary[k] - ary[k + 1];
			}
		}
		printf("Class %d\nMax %d, Min %d, Largest gap %d\n", i+1, ary[0], ary[num2 - 1], num3);
			
		


	}




}
