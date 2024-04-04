#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct robot
{
	int status;
	int forward;
}robot;

robot map[105][105];

typedef struct info
{
	int number;
	char command;
	int count;
}info;

info list[105];

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);

	int num3 = 0;
	int num4 = 0;
	scanf("%d %d", &num3, &num4);
	for (int i = 0; i < num3; i++)
	{
		int x = 0;
		int y = 0;
		char command;
		scanf("%d %d %c", &x, &y, &command);
		if (command == 'N')
		{
			map[y - 1][x - 1].status = i + 1;
			map[y - 1][x - 1].forward = 1;
		}
		else if (command == 'W')
		{
			map[y - 1][x - 1].status = i + 1;
			map[y - 1][x - 1].forward = 2;
		}
		else if (command == 'E')
		{
			map[y - 1][x - 1].status = i + 1;
			map[y - 1][x - 1].forward = 3;
		}
		else if (command == 'S')
		{
			map[y - 1][x - 1].status = i + 1;
			map[y - 1][x - 1].forward = 4;
		}
	}
	for (int i = 0; i < num4; i++)
	{
		scanf("%d %c %d", &list[i].number, &list[i].command, &list[i].count);
	}
	for (int i = 0; i < num4; i++)
	{
		int targetx = -1;
		int targety = -1;
		for (int j = 0; j < num2; j++)
		{
			for (int k = 0; k < num1; k++)
			{
				if (map[j][k].status == list[i].number)
				{
					targetx = k;
					targety = j;
					break;
				}
			}
			if (targety != -1 && targetx != -1)
			{
				break;
			}
		}
		for (int n = 0; n < list[i].count; n++)
		{
			if (list[i].command == 'F')
			{
				if (map[targety][targetx].forward == 1)
				{
					if (map[targety + 1][targetx].status != 0)
					{
						printf("Robot %d crashes into robot %d", list[i].number, map[targety + 1][targetx].status);
						return 0;
					}
					else if (targety + 1 >= num2)
					{
						printf("Robot %d crashes into the wall", list[i].number);
						return 0;
					}
					map[targety + 1][targetx].status = list[i].number;
					map[targety + 1][targetx].forward = 1;
					map[targety][targetx].status = 0;
					map[targety][targetx].forward = 0;
					targety++;
				}
				else if (map[targety][targetx].forward == 2)
				{
					if (map[targety][targetx - 1].status != 0)
					{
						printf("Robot %d crashes into robot %d", list[i].number, map[targety][targetx - 1].status);
						return 0;
					}
					else if (targetx - 1 < 0)
					{
						printf("Robot %d crashes into the wall", list[i].number);
						return 0;
					}
					map[targety][targetx - 1].status = list[i].number;
					map[targety][targetx - 1].forward = 2;
					map[targety][targetx].status = 0;
					map[targety][targetx].forward = 0;
					targetx--;
				}
				else if (map[targety][targetx].forward == 3)
				{
					if (map[targety][targetx + 1].status != 0)
					{
						printf("Robot %d crashes into robot %d", list[i].number, map[targety][targetx + 1].status);
						return 0;
					}
					else if (targetx + 1 >= num1)
					{
						printf("Robot %d crashes into the wall", list[i].number);
						return 0;
					}
					map[targety][targetx + 1].status = list[i].number;
					map[targety][targetx + 1].forward = 3;
					map[targety][targetx].status = 0;
					map[targety][targetx].forward = 0;
					targetx++;
				}
				else if (map[targety][targetx].forward == 4)
				{
					if (map[targety - 1][targetx].status != 0)
					{
						printf("Robot %d crashes into robot %d", list[i].number, map[targety - 1][targetx].status);
						return 0;
					}
					else if (targety - 1 < 0)
					{
						printf("Robot %d crashes into the wall", list[i].number);
						return 0;
					}
					map[targety - 1][targetx].status = list[i].number;
					map[targety - 1][targetx].forward = 4;
					map[targety][targetx].status = 0;
					map[targety][targetx].forward = 0;
					targety--;
				}
			}
			else if (list[i].command == 'L')
			{
				if (map[targety][targetx].forward == 1)
				{
					map[targety][targetx].forward = 2;
				}
				else if (map[targety][targetx].forward == 2)
				{
					map[targety][targetx].forward = 4;
				}
				else if (map[targety][targetx].forward == 3)
				{
					map[targety][targetx].forward = 1;
				}
				else if (map[targety][targetx].forward == 4)
				{
					map[targety][targetx].forward = 3;
				}
			}
			else if (list[i].command == 'R')
			{
				if (map[targety][targetx].forward == 1)
				{
					map[targety][targetx].forward = 3;
				}
				else if (map[targety][targetx].forward == 2)
				{
					map[targety][targetx].forward = 1;
				}
				else if (map[targety][targetx].forward == 3)
				{
					map[targety][targetx].forward = 4;
				}
				else if (map[targety][targetx].forward == 4)
				{
					map[targety][targetx].forward = 2;
				}
			}
		}
	}
	printf("OK");
}