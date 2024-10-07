#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


int main(void)
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);
	
	int count = 0;
	while (1)
	{
		if ((count / num1 >= num2 - 1 && count % num1 != 0) || (count % num1 == 0 && count / num1 >= num2))
		{
			break;
		}
		count++;
		
	}
	printf("%d\n", count);
}