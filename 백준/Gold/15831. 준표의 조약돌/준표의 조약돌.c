#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char map[300005] = { 0, };

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	scanf("%d %d %d", &num1, &num2, &num3);
	scanf("%s", map);
	int start = 0;
	int end = 0;
	int max = 0;
	int white = 0;
	int black = 0;
	while (end < num1)
	{
		if (black > num2)
		{	
			if (map[start] == 'B')
			{
				black--;
				start++;
			}
			else if (map[start] == 'W')
			{
				white--;
				start++;
			}
				
		}
		else
		{
			if (map[end] == 'W')
			{
				white++;
			}
			else
			{
				black++;
			}
			if (white >= num3 && black <= num2)
			{
				if (max < end - start + 1)
				{
					max = end - start + 1;
				}
			}
			end++;
		}
	}
	printf("%d", max);
}