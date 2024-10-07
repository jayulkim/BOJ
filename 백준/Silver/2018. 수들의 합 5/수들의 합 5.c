#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>


int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	
	int count = 0;

	int sum = 1;
	int start = 1;
	int end = 2;

	while (start <= num1)
	{
		sum += end;
		if (sum > num1)
		{
			start++;
			sum = 0;
			end = start;
		}
		else if (sum < num1)
		{
			end++;
			//sum += end;
			//printf("%d\n", end);
			
			//printf("%d\n", sum);
		}
		else
		{
			//printf("%d %d\n", start, end);
			count++;
			start++;
			end = start;
			sum = 0;
		}
		if (start >= end)
		{
			//end++;
		}
		
	}
	if (num1 == 1)
	{
		printf("1\n");
	}
	else
	{
		printf("%d\n", count);
	}
	

}