#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct pos
{
	int x;
	int y;
}pos;

pos list[2000];

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	int q1 = 0;
	int q2 = 0;
	int q3 = 0;
	int q4 = 0;
	int axis = 0;

	for (int i = 0; i < num1; i++)
	{
		scanf("%d %d", &list[i].x, &list[i].y);
		if (list[i].x == 0 || list[i].y == 0)
		{
			axis++;
		}
		else
		{
			if (list[i].x > 0 && list[i].y > 0)
			{
				q1++;
			}
			else if (list[i].x < 0 && list[i].y > 0)
			{
				q2++;
			}
			else if (list[i].x < 0 && list[i].y < 0)
			{
				q3++;
			}
			else if (list[i].x > 0 && list[i].y < 0)
			{
				q4++;
			}
		}
	}
	printf("Q1: %d\nQ2: %d\nQ3: %d\nQ4: %d\nAXIS: %d", q1, q2, q3, q4, axis);

	
	
	
}
