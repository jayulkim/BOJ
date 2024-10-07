#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	while (1)
	{
		int num1 = 0;
		scanf("%d", &num1);

		if (num1 == 0)
		{
			break;
		}

		int result1 = 0;
		
		int num2 = num1 * 2;
		num1++;
		while(num1 <= num2)
		{
			int count = 2;
			int result = 0;

			while (count * count <= num1)
			{
				if (num1 % count == 0)
				{
					result++;
					break;
				}
				count++;
			}
			if (result == 0)
			{
				result1++;
				num1 = num1 + 2;
			}
			else
			{
				if (num1 % 2 == 0)
				{
					num1++;
				}
				else
				{
					num1 = num1 + 2;
				}
			}
		}
		printf("%d\n", result1);
	}
}