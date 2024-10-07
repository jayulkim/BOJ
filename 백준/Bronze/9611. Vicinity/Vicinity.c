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

	for (int i = 0; i < num1; i++)
	{
		scanf("%d %d", &list[i].x, &list[i].y);
	}

	int num2 = 0;
	int number = 0;
	int distence = 0;
	scanf("%d", &num2);

	for (int i = 0; i < num2; i++)
	{
		int result = 0;
		scanf("%d %d", &number, &distence);
		for (int j = 0; j < num1; j++)
		{
			if (number - 1!= j)
			{
				if (sqrt((list[number - 1].x - list[j].x) * (list[number - 1].x - list[j].x) + (list[number - 1].y - list[j].y) * (list[number - 1].y - list[j].y)) <= distence)
				{
					result++;
				}
			}
			
		}
		printf("%d\n", result);
	}



	
	
}