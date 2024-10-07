#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;

	int result = 0;

	scanf("%d %d %d", &num1, &num2, &num3);
	
	for (int i = num1; i <= num2; i++)
	{
		int num4 = 2;
		int count = 0;

		while (num4 * num4 <= i)
		{
			if (i % num4 == 0)
			{
				count++;
				break;
			}
			num4++;
		}
		if (count == 0)
		{
			int ary1[10] = { 0, };
			ary1[0] = i % 10;
			ary1[1] = (i / 10) % 10;
			ary1[2] = (i / 100) % 10;
			ary1[3] = (i / 1000) % 10;
			ary1[4] = (i / 10000) % 10;
			ary1[5] = (i / 100000) % 10;
			ary1[6] = (i / 1000000) % 10;
			if (ary1[0] == num3 || ary1[1] == num3 || ary1[2] == num3 || ary1[3] == num3 || ary1[4] == num3 || ary1[5] == num3 || ary1[6] == num3)
			{
				result++;
			}
		}
		
	}
	printf("%d\n", result);
	

}
