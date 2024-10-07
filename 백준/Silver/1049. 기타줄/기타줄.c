#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main(void)
{
	int num0 = 0;
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;

	int num4 = 1000;
	int num5 = 1000;
	scanf("%d %d", &num0, &num1);

	for (int i = 0; i < num1; i++)
	{
		scanf("%d %d", &num2, &num3);

		if (num2 <= num4)
		{
			num4 = num2;
		}
		if (num3 <= num5)
		{
			num5 = num3;
		}
		
	}

	if (num0 <= 6)
	{
		if (num4 < num5 * num0)
		{
			printf("%d", num4);
		}
		if (num4 > num5 * num0)
		{
			printf("%d", num5 * num0);
		}
		if (num4 == num5 * num0)
		{
			printf("%d", num4);
		}
		
	}
	if (num0 > 6)
	{
		if (((num0 / 6) * num4) + ((num0 - (6 * (num0 / 6))) * num5) < (num4 * ((num0 / 6) + 1)) && ((num0 / 6) * num4) + ((num0 - (6 * (num0 / 6))) * num5) < num5 * num0)
		{
			printf("%d", ((num0 / 6) * num4) + ((num0 - (6 * (num0 / 6))) * num5));
		}
		if ((num4 * ((num0 / 6) + 1)) < ((num0 / 6) * num4) + ((num0 - (6 * (num0 / 6))) * num5) && (num4 * ((num0 / 6) + 1)) < num5 * num0)
		{
			printf("%d", (num4 * ((num0 / 6) + 1)));
		}
		if (num5 * num0 < (num4 * ((num0 / 6) + 1)) && num5 * num0 < ((num0 / 6) * num4) + ((num0 - (6 * (num0 / 6))) * num5))
		{
			printf("%d", num5 * num0);
		}
		if (((num0 / 6) * num4) + ((num0 - (6 * (num0 / 6))) * num5) == (num4 * ((num0 / 6) + 1)) && ((num0 / 6) * num4) + ((num0 - (6 * (num0 / 6))) * num5) < num5 * num0)
		{
			printf("%d", ((num0 / 6) * num4) + ((num0 - (6 * (num0 / 6))) * num5));
		}
		
		if (((num0 / 6) * num4) + ((num0 - (6 * (num0 / 6))) * num5) == (num4 * ((num0 / 6) + 1)) && ((num0 / 6) * num4) + ((num0 - (6 * (num0 / 6))) * num5) == num5 * num0)
		{
			printf("%d", num5 * num0);
		}
		if (((num0 / 6) * num4) + ((num0 - (6 * (num0 / 6))) * num5) == num5 * num0 && ((num0 / 6) * num4) + ((num0 - (6 * (num0 / 6))) * num5) < (num4 * ((num0 / 6) + 1)))
		{
			printf("%d", ((num0 / 6) * num4) + ((num0 - (6 * (num0 / 6))) * num5));
		}
		
		if (num5 * num0 == (num4 * ((num0 / 6) + 1)) && num5 * num0 < ((num0 / 6) * num4) + ((num0 - (6 * (num0 / 6))) * num5))
		{
			printf("%d", (num4 * ((num0 / 6) + 1)));
		}
		
	}
}