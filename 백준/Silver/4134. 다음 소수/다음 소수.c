#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		long long int num2 = 0;
		scanf("%lld", &num2);

		while (1)
		{
			long long int num3 = 2;
			int count = 0;

			while (num3 * num3 <= num2)
			{
				if (num2 % num3 == 0)
				{
					count++;
					break;
				}
				num3++;
			}
			if (count == 0)
			{
				break;
			}
			else
			{
				if (num2 % 2 == 0)
				{
					num2++;
				}
				else if (num2 % 2 == 1)
				{
					num2 = num2 + 2;
				}
			}
		}
		if (num2 != 1 && num2 != 0)
		{
			printf("%lld\n", num2);
		}
		else if (num2 == 1)
		{
			printf("%d\n", 2);
		}
		else if (num2 == 0)
		{
			printf("%d\n", 2);
		}


	}

}
