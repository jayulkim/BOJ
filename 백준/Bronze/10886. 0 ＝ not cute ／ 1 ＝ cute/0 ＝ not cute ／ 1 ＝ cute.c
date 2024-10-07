#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int ary[105] = { 0, };

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	int num2 = 0;
	int num3 = 0;
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary[i]);
		if (ary[i] == 1)
		{
			num2++;
		}
		else if (ary[i] == 0)
		{
			num3++;
		}
		
	}
	if (num3 > num2)
	{
		printf("Junhee is not cute!");
	}
	else
	{
		printf("Junhee is cute!");
	}
	

}