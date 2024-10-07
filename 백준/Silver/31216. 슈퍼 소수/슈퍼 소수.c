#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int ary1[400000] = {0,};
int ary2[400000] = { 0, };

int main(void)
{
	int num1 = 0;

	scanf("%d", &num1);

	int num3 = 0;
	
	ary2[0] = 2;

	int index = 3;
	int index1 = 1;
	while (index <= 318137)
	{
		int count = 2;
		int result = 0;
		while (count * count <= index)
		{
			if (index % count == 0)
			{
				result++;
				break;
			}
			count++;
			
		}
		if (result == 0)
		{
			ary2[index1] = index;
			index1++;
		}
		index = index + 2;
	}
	
	int num2 = 3;
	int index2 = 1;
	while (num2 <= 318137)
	{
		int count1 = 2;
		int result1 = 0;
		while (count1 * count1 <= num2)
		{
			if (num2 % count1 == 0)
			{
				result1++;
				break;
			}
			count1++;
		}
		if (result1 == 0)
		{
			ary1[index2] = ary2[num2 - 1];
			index2++;
		}
		num2 = num2 + 2;

	}
	ary1[0] = 3;

	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &num3);

		printf("%d\n", ary1[num3 - 1]);
	}

}