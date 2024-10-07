#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

int ary[50] = { 0, };

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		int num2 = 0;
		int num3 = 0;
		int num4 = 0;
		scanf("%d %d %d", &num2, &num3, &num4);

		if (num3 - num4 > num2)
		{
			printf("advertise\n");
		}
		else if (num3 - num4 < num2)
		{
			printf("do not advertise\n");
		}
		else
		{
			printf("does not matter\n");
		}
	}

}