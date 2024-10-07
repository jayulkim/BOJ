#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num1 = 0;

	scanf("%d", &num1);

	int count = 100;

	int result = 99;

	if (num1 < 100)
	{
		printf("%d\n", num1);
	}
	else if (num1 >= 100 && num1 < 1000)
	{
		while (count <= num1)
		{
			int ary1[3] = { 0, };
			ary1[0] = count / 100;
			ary1[1] = (count / 10) % 10;
			ary1[2] = count % 10;
			
			if ((ary1[0] + ary1[2]) == ary1[1] * 2)
			{
				
				result++;
			}
			count++;

		}
		printf("%d\n", result);
	}
	else if (num1 == 1000)
	{
		printf("144\n");
	}
	
}