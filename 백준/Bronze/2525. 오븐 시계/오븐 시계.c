#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	scanf("%d %d", &num1, &num2);
	scanf("%d", &num3);

	if (num2 + num3 < 60)
	{
		printf("%d %d", num1, num2 + num3);
	}
	if (num2 + num3 >= 60)
	{
		num1 += (num2 + num3) / 60;
		num2 = (num2 + num3) % 60;
		if (num1 >= 24)
		{
			num1 = num1 % 24;
		}
		printf("%d %d", num1, num2);
	}	
	

}