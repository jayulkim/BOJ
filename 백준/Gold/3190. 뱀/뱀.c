#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int map[105][105] = { 0, };

typedef struct pos
{
	int x;
	int y;
}pos;

typedef struct Dq
{
	int headdown;
	int headup;
	int size;
	pos* dq;
}Dq;

Dq* create(int size)
{
	Dq* new = (Dq*)malloc(sizeof(Dq));
	new->headdown = 0;
	new->headup = 0;
	new->size = size + 1;
	new->dq = (pos*)malloc(sizeof(pos) * new->size);
	return new;
}

void push_front(Dq* dq, int y, int x)
{
	dq->dq[dq->headdown].x = x;
	dq->dq[dq->headup].y = y;
	dq->headdown = (dq->headdown - 1 + dq->size) % dq->size;
}

pos pop_front(Dq* dq)
{
	pos temp = dq->dq[dq->headdown];
	dq->headdown = (dq->headdown + 1) % dq->size;
	return dq->dq[dq->headdown];
}

void push_back(Dq* dq, int y, int x)
{
	dq->headup = (dq->headup + 1) % dq->size;
	dq->dq[dq->headup].x = x;
	dq->dq[dq->headup].y = y;
}
 
pos pop_back(Dq* dq)
{
	dq->headup = (dq->headup - 1 + dq->size) % dq->size;
	return dq->dq[dq->headup];
}

typedef struct command
{
	int count;
	char forward;
}command;

command com[105];

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	Dq* list = create(num1 * num1);

	int num2 = 0;
	scanf("%d", &num2);
	for (int i = 0; i < num2; i++)
	{
		int num3 = 0;
		int num4 = 0;
		scanf("%d %d", &num3, &num4);
		map[num3 - 1][num4 - 1] = 1;
	}

	int num5 = 0;
	scanf("%d", &num5);
	for (int i = 0; i < num5; i++)
	{
		scanf("%d %c", &com[i].count, &com[i].forward);
	}

	push_back(list, 0, 0);

	for (int i = 0; i < com[0].count; i++)
	{
		push_back(list, 0, i + 1);
		if (map[list->dq[list->headup].y][list->dq[list->headup].x] == 0)
		{
			map[list->dq[list->headup].y][list->dq[list->headup].x] = -1;
			map[pop_front(list).y][list->dq[list->headdown].x] = 0;
		}
		else if (map[list->dq[list->headup].y][list->dq[list->headup].x] == 1)
		{
			map[list->dq[list->headup].y][list->dq[list->headup].x] = -1;
		}
	}

	map[0][com[0].count] = -1;

	int up = 0;
	int down = 0;
	int right = 0;
	int left = 0;
	if (com[0].forward == 'D')
	{
		down = 1;
	}
	else if (com[0].forward = 'L')
	{
		printf("%d", com[0].count + 1);
		return 0;
	}
	int sec = com[0].count;

	for (int i = 1; i < num5; i++)
	{	
		for (int j = 0; j < com[i].count - com[i - 1].count; j++)
		{
		//	printf("%d %d\n", list->dq[list->headdown].y, list->dq[list->headdown].x);
			//printf("%d %d\n", list->dq[list->headup].y, list->dq[list->headup].x);
			
			if (right == 1)
			{
				push_back(list, list->dq[list->headup].y, list->dq[list->headup].x + 1);
				sec++;
				if (list->dq[list->headup].x >= num1)
				{
					printf("%d", sec);
					return 0;
				}
				else

				{
					if (map[list->dq[list->headup].y][list->dq[list->headup].x] == -1)
					{
						printf("%d", sec);
						return 0;
					}
					else if (map[list->dq[list->headup].y][list->dq[list->headup].x] == 0)
					{
						map[list->dq[list->headup].y][list->dq[list->headup].x] = -1;
						map[pop_front(list).y][list->dq[list->headdown].x] = 0;
					}
					else if (map[list->dq[list->headup].y][list->dq[list->headup].x] == 1)
					{
						map[list->dq[list->headup].y][list->dq[list->headup].x] = -1;
					}
				}
				
			}
			else if (left == 1)
			{
				push_back(list, list->dq[list->headup].y, list->dq[list->headup].x - 1);
				sec++;
				if (list->dq[list->headup].x < 0)
				{
					printf("%d", sec);
					return 0;
				}
				else
				{
					if (map[list->dq[list->headup].y][list->dq[list->headup].x] == -1)
					{
						printf("%d", sec);
						return 0;
					}
					else if (map[list->dq[list->headup].y][list->dq[list->headup].x] == 0)
					{
						map[list->dq[list->headup].y][list->dq[list->headup].x] = -1;
						map[pop_front(list).y][list->dq[list->headdown].x] = 0;
					}
					else if (map[list->dq[list->headup].y][list->dq[list->headup].x] == 1)
					{
						map[list->dq[list->headup].y][list->dq[list->headup].x] = -1;
					}
				}
			}
			else if (down == 1)
			{
				push_back(list, list->dq[list->headup].y + 1, list->dq[list->headup].x);
				sec++;
				if (list->dq[list->headup].y >= num1)
				{
					printf("%d", sec);
					return 0;
				}
				else
				{
					if (map[list->dq[list->headup].y][list->dq[list->headup].x] == -1)
					{
						//printf("%d %d\n", list->dq[list->headdown].y, list->dq[list->headdown].x);
						//printf("%d %d\n", list->dq[list->headup].y, list->dq[list->headup].x);
						printf("%d", sec);
						return 0;
					}
					else if (map[list->dq[list->headup].y][list->dq[list->headup].x] == 0)
					{
						map[list->dq[list->headup].y][list->dq[list->headup].x] = -1;
						map[pop_front(list).y][list->dq[list->headdown].x] = 0;
					}
					else if (map[list->dq[list->headup].y][list->dq[list->headup].x] == 1)
					{
						map[list->dq[list->headup].y][list->dq[list->headup].x] = -1;
					//	printf("%d %d\n", list->dq[list->headdown].y, list->dq[list->headdown].x);
					//	printf("%d %d\n", list->dq[list->headup].y, list->dq[list->headup].x);
					}
				}	
			}
			else if (up == 1)
			{
				push_back(list, list->dq[list->headup].y - 1, list->dq[list->headup].x);
				sec++;
				if (list->dq[list->headup].y < 0)
				{
					printf("%d", sec);
					return 0;
				}
				else
				{
					if (map[list->dq[list->headup].y][list->dq[list->headup].x] == -1)
					{
						printf("%d", sec);
						return 0;
					}
					else if (map[list->dq[list->headup].y][list->dq[list->headup].x] == 0)
					{
						map[list->dq[list->headup].y][list->dq[list->headup].x] = -1;
						map[pop_front(list).y][list->dq[list->headdown].x] = 0;
					}
					else if (map[list->dq[list->headup].y][list->dq[list->headup].x] == 1)
					{
						map[list->dq[list->headup].y][list->dq[list->headup].x] = -1;
					}
				}
			}
		}
		if (down == 1)
		{
			if (com[i].forward == 'D')
			{
				down = 0;
				left = 1;
			}
			else if (com[i].forward == 'L')
			{
				down = 0;
				right = 1;
			}
		}
		else if (up == 1)
		{
			if (com[i].forward == 'D')
			{
				up = 0;
				right = 1;
			}
			else if (com[i].forward == 'L')
			{
				up = 0;
				left = 1;
			}
		}
		else if (right == 1)
		{
			if (com[i].forward == 'D')
			{
				right = 0;
				down = 1;
			}
			else if (com[i].forward == 'L')
			{
				right = 0;
				up = 1;
			}
		}
		else if (left == 1)
		{
			if (com[i].forward == 'D')
			{
				left = 0;
				up = 1;
			}
			else if (com[i].forward == 'L')
			{
				left = 0;
				down = 1;
			}
		}
		for (int i = 0; i < num1 + 1; i++)
		{
			for (int j = 0; j < num1 + 1; j++)
			{
				//printf("%d ", map[i][j]);
			}
			//printf("\n");
		}
		
	}
	
	while (1)
	{
		if (right == 1)
		{
			push_back(list, list->dq[list->headup].y, list->dq[list->headup].x + 1);
			sec++;
			if (list->dq[list->headup].x >= num1)
			{
				printf("%d", sec);
				return 0;
			}
			else

			{
				if (map[list->dq[list->headup].y][list->dq[list->headup].x] == -1)
				{
					printf("%d", sec);
					return 0;
				}
				else if (map[list->dq[list->headup].y][list->dq[list->headup].x] == 0)
				{
					map[list->dq[list->headup].y][list->dq[list->headup].x] = -1;
					map[pop_front(list).y][list->dq[list->headdown].x] = 0;
				}
				else if (map[list->dq[list->headup].y][list->dq[list->headup].x] == 1)
				{
					map[list->dq[list->headup].y][list->dq[list->headup].x] = -1;
				}
			}

		}
		else if (left == 1)
		{
			push_back(list, list->dq[list->headup].y, list->dq[list->headup].x - 1);
			sec++;
			if (list->dq[list->headup].x < 0)
			{
				printf("%d", sec);
				return 0;
			}
			else
			{
				if (map[list->dq[list->headup].y][list->dq[list->headup].x] == -1)
				{
					printf("%d", sec);
					return 0;
				}
				else if (map[list->dq[list->headup].y][list->dq[list->headup].x] == 0)
				{
					map[list->dq[list->headup].y][list->dq[list->headup].x] = -1;
					map[pop_front(list).y][list->dq[list->headdown].x] = 0;
				}
				else if (map[list->dq[list->headup].y][list->dq[list->headup].x] == 1)
				{
					map[list->dq[list->headup].y][list->dq[list->headup].x] = -1;
				}
			}
		}
		else if (down == 1)
		{
			push_back(list, list->dq[list->headup].y + 1, list->dq[list->headup].x);
			sec++;
			if (list->dq[list->headup].y >= num1)
			{
				printf("%d", sec);
				return 0;
			}
			else
			{
				if (map[list->dq[list->headup].y][list->dq[list->headup].x] == -1)
				{
					//printf("%d %d\n", list->dq[list->headdown].y, list->dq[list->headdown].x);
					//printf("%d %d\n", list->dq[list->headup].y, list->dq[list->headup].x);
					printf("%d", sec);
					return 0;
				}
				else if (map[list->dq[list->headup].y][list->dq[list->headup].x] == 0)
				{
					map[list->dq[list->headup].y][list->dq[list->headup].x] = -1;
					map[pop_front(list).y][list->dq[list->headdown].x] = 0;
				}
				else if (map[list->dq[list->headup].y][list->dq[list->headup].x] == 1)
				{
					map[list->dq[list->headup].y][list->dq[list->headup].x] = -1;
					//	printf("%d %d\n", list->dq[list->headdown].y, list->dq[list->headdown].x);
					//	printf("%d %d\n", list->dq[list->headup].y, list->dq[list->headup].x);
				}
			}
		}
		else if (up == 1)
		{
			push_back(list, list->dq[list->headup].y - 1, list->dq[list->headup].x);
			sec++;
			if (list->dq[list->headup].y < 0)
			{
				printf("%d", sec);
				return 0;
			}
			else
			{
				if (map[list->dq[list->headup].y][list->dq[list->headup].x] == -1)
				{
					printf("%d", sec);
					return 0;
				}
				else if (map[list->dq[list->headup].y][list->dq[list->headup].x] == 0)
				{
					map[list->dq[list->headup].y][list->dq[list->headup].x] = -1;
					map[pop_front(list).y][list->dq[list->headdown].x] = 0;
				}
				else if (map[list->dq[list->headup].y][list->dq[list->headup].x] == 1)
				{
					map[list->dq[list->headup].y][list->dq[list->headup].x] = -1;
				}
			}
		}
	}
}