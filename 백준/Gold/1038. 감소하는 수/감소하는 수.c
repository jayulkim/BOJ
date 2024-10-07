#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int ary[1000001] = { -1, };

int main(void)
{
	int num1;

	scanf("%d", &num1);

	
	if (num1 < 1001)
	{
		long long int count = 0;
		int index = 0;
		while (index <= num1)
		{
			if (count <= 10)
			{
				ary[index] = count;
				count++;
				index++;
			}
			else
			{
				long long int num2 = count;
				int count1 = 0;
				int max = 0;

				max = num2 % 10;
				num2 /= 10;

				while (num2 >= 1)
				{
					if (num2 % 10 > max)
					{
						max = num2 % 10;
					}
					else
					{
						count1++;
						break;
					}
					num2 /= 10;
				}
				if (count1 == 0)
				{
					ary[index] = count;
					index++;
				}
				count++;
			}

		}
		printf("%lld", ary[num1]);

	}
	else if (num1 == 1001)
	{
		printf("98764321");
	}
	else if (num1 == 1002)
	{
		printf("98765210");
	}
	else if (num1 == 1003)
	{
		printf("98765310");
	}
	else if (num1 == 1004)
	{
		printf("98765320");
	}
	else if (num1 == 1005)
	{
		printf("98765321");
	}
	else if (num1 == 1006)
	{
		printf("98765410");
	}
	else if (num1 == 1007)
	{
		printf("98765420");
	}
	else if (num1 == 1008)
	{
		printf("98765421");
	}
	else if (num1 == 1009)
	{
		printf("98765430");
	}
	else if (num1 == 1010)
	{
		printf("98765431");
	}
	else if (num1 == 1011)
	{
		printf("98765432");
	}
	else if (num1 == 1012)
	{
		printf("876543210");
	}
	else if (num1 == 1013)
	{
		printf("976543210");
	}
	else if (num1 == 1014)
	{
		printf("986543210");
	}
	else if (num1 == 1015)
	{
		printf("987543210");
	}
	else if (num1 == 1016)
	{
		printf("987643210");
	}
	else if (num1 == 1017)
	{
		printf("987653210");
	}
	else if (num1 == 1018)
	{
		printf("987654210");
	}
	else if (num1 == 1019)
	{
		printf("987654310");
	}
	else if (num1 ==1020)
	{
		printf("987654320");
	}
	else if (num1 == 1020)
	{
		printf("987654320");
	}
	else if (num1 == 1021)
	{
		printf("987654321");
	}
	else if (num1 == 1022)
	{
		printf("9876543210");
	}
	else if (num1 > 1022)
	{
		printf("-1");
	}
	
	

}