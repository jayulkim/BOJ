#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int num4 = 0;
	int num5 = 0;
	int num6 = 0;
	int num7 = 0;
	int num8 = 0;
	int num9 = 0;
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int ary[9][9] = { 0, };

	for (int i = 0; i < 9; i++)
	{
		scanf("%d %d %d %d %d %d %d %d %d", &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8, &num9);
		ary[i][0] = num1;
		ary[i][1] = num2;
		ary[i][2] = num3;
		ary[i][3] = num4;
		ary[i][4] = num5;
		ary[i][5] = num6;
		ary[i][6] = num7;
		ary[i][7] = num8;
		ary[i][8] = num9;	
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (ary[i][j] >= count1)
			{
				count1 = ary[i][j];
				count2 = i;
				count3 = j;
			}
		}
	}
	printf("%d\n", count1);
	printf("%d %d", count2 + 1, count3+ 1);
}