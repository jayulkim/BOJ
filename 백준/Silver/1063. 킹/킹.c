#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
typedef struct pos
{
	int kingX;
	int kingY;

	int rockX;
	int rockY;
}pos;

pos list[100];

int main(void)
{
	int num1 = 0;
	
	char kX[5];
	int kY;

	char rX[5];
	int rY;

	scanf("%c%d %c%d %d", &kX[0], &kY, &rX[0], &rY, &num1);

	
	list[0].kingX = kX[0] - 64;
	list[0].kingY = kY;
	list[0].rockX = rX[0] - 64;
	list[0].rockY = rY;
	
	for (int i = 1; i <= num1; i++)
	{
		char move[5] = { "" };

		scanf("%s", move);

		char move1 = move[0];
		char move2 = move[1];

		if (move1 == 'R')
		{
			list[i].rockX = list[i - 1].rockX;
			list[i].rockY = list[i - 1].rockY;
			if (list[i - 1].kingX + 1 <= 8)
			{
				list[i].kingX = list[i - 1].kingX + 1;
				list[i].kingY = list[i - 1].kingY;

				
				if (list[i].rockX == list[i].kingX && list[i].rockY == list[i].kingY)
				{
					if (list[i - 1].rockX + 1 <= 8)
					{
						list[i].rockX += 1;
					}
					else
					{
						list[i].rockX = list[i - 1].rockX;
						list[i].rockY = list[i - 1].rockY;

						list[i].kingX = list[i - 1].kingX;
						list[i].kingY = list[i - 1].kingY;
					}
				}
			}
			else
			{
				list[i].kingX = list[i - 1].kingX;
				list[i].kingY = list[i - 1].kingY;
				
			}

		}
		if (move1 == 'L')
		{
			list[i].rockX = list[i - 1].rockX;
			list[i].rockY = list[i - 1].rockY;
			if (list[i - 1].kingX - 1 > 0)
			{
				list[i].kingX = list[i - 1].kingX - 1;
				list[i].kingY = list[i - 1].kingY;

				
				if (list[i].rockX == list[i].kingX && list[i].rockY == list[i].kingY)
				{
					if (list[i - 1].rockX - 1 > 0)
					{
						list[i].rockX -= 1;
					}
					else
					{
						list[i].rockX = list[i - 1].rockX;
						list[i].rockY = list[i - 1].rockY;

						list[i].kingX = list[i - 1].kingX;
						list[i].kingY = list[i - 1].kingY;
					}
				}
			}
			else
			{
				list[i].kingX = list[i - 1].kingX;
				list[i].kingY = list[i - 1].kingY;
				
			}

		}
		if (move1 == 'B')
		{
			list[i].rockX = list[i - 1].rockX;
			list[i].rockY = list[i - 1].rockY;
			if (list[i - 1].kingY - 1 > 0)
			{
				list[i].kingX = list[i - 1].kingX ;
				list[i].kingY = list[i - 1].kingY - 1;

				
				if (list[i].rockX == list[i].kingX && list[i].rockY == list[i].kingY)
				{
					if (list[i - 1].rockY - 1 > 0)
					{
						list[i].rockY -= 1;
					}
					else
					{
						list[i].rockX = list[i - 1].rockX;
						list[i].rockY = list[i - 1].rockY;

						list[i].kingX = list[i - 1].kingX;
						list[i].kingY = list[i - 1].kingY;
					}
				}
				
			}
			else
			{
				list[i].kingX = list[i - 1].kingX;
				list[i].kingY = list[i - 1].kingY;
				
			}
		}
		if (move1 == 'T')
		{
			list[i].rockX = list[i - 1].rockX;
			list[i].rockY = list[i - 1].rockY;
			if (list[i - 1].kingY + 1 <= 8)
			{
				list[i].kingX = list[i - 1].kingX;
				list[i].kingY = list[i - 1].kingY + 1;

				
				if (list[i].rockX == list[i].kingX && list[i].rockY == list[i].kingY)
				{
					if (list[i - 1].rockY + 1 <= 8)
					{
						list[i].rockY += 1;
					}
					else
					{
						list[i].rockX = list[i - 1].rockX;
						list[i].rockY = list[i - 1].rockY;

						list[i].kingX = list[i - 1].kingX;
						list[i].kingY = list[i - 1].kingY;
					}
				}
			}
			else
			{
				list[i].kingX = list[i - 1].kingX;
				list[i].kingY = list[i - 1].kingY;
			}
		}
		if (move1 == 'R' && move2 == 'T')
		{

			list[i].rockX = list[i - 1].rockX;
			list[i].rockY = list[i - 1].rockY;
			if (list[i - 1].kingY + 1 <= 8 && list[i - 1].kingX + 1 <= 8)
			{

				list[i].kingX = list[i - 1].kingX + 1;
				list[i].kingY = list[i - 1].kingY + 1;

				if (list[i].rockX == list[i].kingX && list[i].rockY == list[i].kingY)
				{
					if (list[i - 1].rockY + 1 <= 8 && list[i - 1].rockX + 1 <= 8)
					{
						list[i].rockX += 1;
						list[i].rockY += 1;
					}
					else
					{
						list[i].rockX = list[i - 1].rockX;
						list[i].rockY = list[i - 1].rockY;

						list[i].kingX = list[i - 1].kingX;
						list[i].kingY = list[i - 1].kingY;
					}
				}
			}
			else
			{
				list[i].kingX = list[i - 1].kingX;
				list[i].kingY = list[i - 1].kingY;
			}

		}
		if (move1 == 'L' && move2 == 'T')
		{

			list[i].rockX = list[i - 1].rockX;
			list[i].rockY = list[i - 1].rockY;

			if (list[i - 1].kingY + 1 <= 8 && list[i - 1].kingX - 1 > 0)
			{
				list[i].kingX = list[i - 1].kingX - 1;
				list[i].kingY = list[i - 1].kingY + 1;

				if (list[i].rockX == list[i].kingX && list[i].rockY == list[i].kingY)
				{
					if (list[i - 1].rockY + 1 <= 8 && list[i - 1].rockX - 1 > 0)
					{
						list[i].rockX -= 1;
						list[i].rockY += 1;
					}
					else
					{
						list[i].rockX = list[i - 1].rockX;
						list[i].rockY = list[i - 1].rockY;

						list[i].kingX = list[i - 1].kingX;
						list[i].kingY = list[i - 1].kingY;
					}
				}
			}
			else
			{
				list[i].kingX = list[i - 1].kingX;
				list[i].kingY = list[i - 1].kingY;
			}
		}
		if (move1 == 'R' && move2 == 'B')
		{

			list[i].rockX = list[i - 1].rockX;
			list[i].rockY = list[i - 1].rockY;
			if (list[i - 1].kingY - 1 > 0 && list[i - 1].kingX + 1 <= 8)
			{
				list[i].kingX = list[i - 1].kingX + 1;
				list[i].kingY = list[i - 1].kingY - 1;

				if (list[i].rockX == list[i].kingX && list[i].rockY == list[i].kingY)
				{
					if (list[i - 1].rockY - 1 > 0 && list[i - 1].rockX + 1 <= 8)
					{
						list[i].rockX += 1;
						list[i].rockY -= 1;
					}
					else
					{
						list[i].rockX = list[i - 1].rockX;
						list[i].rockY = list[i - 1].rockY;

						list[i].kingX = list[i - 1].kingX;
						list[i].kingY = list[i - 1].kingY;
					}
				}
			}
			else
			{
				list[i].kingX = list[i - 1].kingX;
				list[i].kingY = list[i - 1].kingY;
			
			}
		}
		if (move1 == 'L' && move2 == 'B')
		{

			list[i].rockX = list[i - 1].rockX;
			list[i].rockY = list[i - 1].rockY;
			if (list[i - 1].kingY - 1 > 0 && list[i - 1].kingX -1 > 0)
			{
				list[i].kingX = list[i - 1].kingX - 1;
				list[i].kingY = list[i - 1].kingY - 1;
			
				if (list[i].rockX == list[i].kingX && list[i].rockY == list[i].kingY)
				{
					if (list[i - 1].rockY - 1 > 0 && list[i - 1].rockX - 1 > 0)
					{
						list[i].rockX -= 1;
						list[i].rockY -= 1;
					}
					else
					{
						list[i].rockX = list[i - 1].rockX;
						list[i].rockY = list[i - 1].rockY;

						list[i].kingX = list[i - 1].kingX;
						list[i].kingY = list[i - 1].kingY;
					}
				}
			}
			else
			{
				list[i].kingX = list[i - 1].kingX;
				list[i].kingY = list[i - 1].kingY;
			
			}
		}
	}
	char kingX[5];
	char rockX[5];

	if (list[num1].kingX == 1)
	{
		kingX[0] = 'A';
	}
	else if (list[num1].kingX == 2)
	{
		kingX[0] = 'B';
	}
	else if (list[num1].kingX == 3)
	{
		kingX[0] = 'C';
	}
	else if (list[num1].kingX == 4)
	{
		kingX[0] = 'D';
	}
	else if (list[num1].kingX == 5)
	{
		kingX[0] = 'E';
	}
	else if (list[num1].kingX == 6)
	{
		kingX[0] = 'F';
	}
	else if (list[num1].kingX == 7)
	{
		kingX[0] = 'G';
	}
	else if (list[num1].kingX == 8)
	{
		kingX[0] = 'H';
	}
	if (list[num1].rockX == 1)
	{
		rockX[0] = 'A';
	}
	else if (list[num1].rockX == 2)
	{
		rockX[0] = 'B';
	}
	else if (list[num1].rockX == 3)
	{
		rockX[0] = 'C';
	}
	else if (list[num1].rockX == 4)
	{
		rockX[0] = 'D';
	}
	else if (list[num1].rockX == 5)
	{
		rockX[0] = 'E';
	}
	else if (list[num1].rockX == 6)
	{
		rockX[0] = 'F';
	}
	else if (list[num1].rockX == 7)
	{
		rockX[0] = 'G';
	}
	else if (list[num1].rockX == 8)
	{
		rockX[0] = 'H';
	}

	printf("%c%d\n%c%d", kingX[0], list[num1].kingY, rockX[0], list[num1].rockY);
	
}