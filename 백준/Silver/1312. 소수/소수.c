#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int num = 0;
	scanf("%d %d %d", &num1, &num2, &num);
	int num3 = num1 / num2;

	int num4 = num1 % num2;

	int num6 = 0;
	for (int i = 0; i < num; i++)
	{
		
	
		num4 *= 10;
		num6 = num4 / num2;
		
		num4 %= num2;
	}
	printf("%d\n", num6);

}