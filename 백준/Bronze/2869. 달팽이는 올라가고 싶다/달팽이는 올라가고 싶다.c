#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int result = 0;
	int count = 0;
	scanf("%d %d %d", &num1, &num2, &num3);



	
	if (num1 != num2)
	{
		if (num3 > num1 && ((num3 - num1) % (num1 - num2)) != 0)
		{
			printf("%d", ((num3 - num1) / (num1 - num2)) + 2);
			
		}
		if (num3 > num1 && ((num3 - num1) % (num1 - num2)) == 0)
		{
			printf("%d", ((num3 - num1) / (num1 - num2)) + 1);
		}
	}
	if (num1 >= num3)
	{
		printf("%d", 1);
	}
}