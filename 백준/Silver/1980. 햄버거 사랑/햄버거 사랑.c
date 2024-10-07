#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ary1[10000] = { 0, };

int ary2[10000] = { 0, };

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;

	scanf("%d %d %d", &num1, &num2, &num3);

	if (num1 < num2 && num2 <= num3)
	{
		int num5 = (num3 / num1) * num1;
		int num6 = 10000;

		
		int index = 0;
		int index1 = 0;
		while (num5 >= 0)
		{
			ary2[index] = num5;
			ary1[index] = (num3 - num5);
			num5 = num5 - num1;
			
			index++;

		}
		for (int i = 0; i < index; i++)
		{
			if (ary1[i] % num2 < num6)
			{
				num6 = ary1[i] % num2;
				index1 = i;
			}
			
		}
		printf("%d %d\n", ary2[index1] / num1 + ary1[index1] / num2, num6);
	}
	else if (num1 >= num2 && num1 <= num3)
	{
		int num5 = (num3 / num2) * num2;
		int num6 = 10000;

		int index = 0;
		int index1 = 0;
		while (num5 >= 0)
		{
			ary2[index] = num5;
			ary1[index] = (num3 - num5);
			num5 = num5 - num2;

			index++;

		}
		for (int i = 0; i < index; i++)
		{
			if (ary1[i] % num1 < num6)
			{
				num6 = ary1[i] % num1;
				index1 = i;
			}

		}
		printf("%d %d\n", ary2[index1] / num2 + ary1[index1] / num1, num6);
	}
	else if (num1 < num2 && num2 > num3 && num1 <= num3)
	{
		printf("%d %d\n", num3 / num1, num3 % num1);
	}
	else if (num1 < num2 && num2 > num3 && num1 > num3)
	{
		printf("%d %d\n", 0, num3);
	}
	else if (num1 >= num2 && num1 > num3 && num2 <= num3)
	{
		printf("%d %d\n", num3 / num2, num3 % num2);
	}
	else if (num1 >= num2 && num1 > num3 && num2 > num3)
	{
		printf("%d %d\n", 0, num3);
	}

}