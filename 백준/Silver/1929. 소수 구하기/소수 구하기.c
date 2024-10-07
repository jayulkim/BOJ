#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num1 = 0;
	int num2 = 0;

	scanf("%d %d", &num1, &num2);

	for (int i = num1; i <= num2; i++)
	{
		int count = 2;
		int result = 0;
		while(count * count <= i)
		{
			if (i % count == 0)
			{
				result++;
				break;
			}
			count++;
		}
		if (result == 0 && i != 1)
		{
			printf("%d\n", i);
		}
	}
}