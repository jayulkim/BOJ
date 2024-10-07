#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int ary[1005] = { 0, };

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);

	for (int i = 0; i < num2; i++)
	{
		scanf("%d", &ary[i]);
	}
	
	int count = 1;
	int sum = 0;
	while (count <= num1)
	{
		int count1 = 0;
		for (int i = 0; i < num2; i++)
		{
			if (count % ary[i] == 0)
			{
				count1++;
				break;
			}
		}
		if (count1 != 0)
		{
			sum += count;
		}
		count++;
	}
	printf("%d\n", sum);
	
}
