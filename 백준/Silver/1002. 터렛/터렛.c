#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <memory.h>


int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		int x1 = 0;
		int y1 = 0;
		int r1 = 0;

		int x2 = 0;
		int y2 = 0;
		int r2 = 0;

		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		int count = 0;
		int count1 = 0;
		int dis = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
		if (r1 == r2 && x1 == x2 && y1 == y2)
		{
			count++;
			printf("-1\n");
		}
		if (count == 0)
		{
			if (r1 != r2 && x1 == x2 && y1 == y2)
			{
				count1++;
				printf("0\n");
			}
			if (count1 == 0)
			{
				if (r1 > r2)
				{
					if (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) > r1 + r2 || r1 > sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) + r2)
					{
						printf("0\n");
					}
					else if (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) == r1 + r2 || r1 == sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) + r2)
					{
						printf("1\n");
					}
					else
					{
						printf("2\n");
					}
				}
				else if (r1 <= r2)
				{
					if (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) > r1 + r2 || r2 > sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) + r1)
					{
						printf("0\n");
					}
					else if (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) == r1 + r2 || r2 == sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) + r1)
					{
						printf("1\n");
					}
					else
					{
						printf("2\n");
					}
				}
			}
		}
		
		
		

	}
}