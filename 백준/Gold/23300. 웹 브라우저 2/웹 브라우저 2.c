#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int frontstack[20005] = { 0, };
int backstack[20005] = { 0, };
int newbackstack[20005] = { 0, };
int newbackhead = -1;
int newbackheaddown = 0;
int fronthead = -1;
int backhead = -1;

int emptynew(int* newbackstack)
{
	if (newbackhead == newbackheaddown-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void new_push(int* newbackstack, int num)
{
	newbackstack[++newbackhead] = num;
}

int new_pop(int* newbackstack)
{
	return newbackstack[newbackheaddown++];
}

int frontempty(int* frontstack)
{
	if (fronthead == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int backempty(int* backstack)
{
	if (backhead == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void front_push(int* frontstack, int num)
{
	frontstack[++fronthead] = num;
}
void back_push(int* backstack, int num)
{
	backstack[++backhead] = num;
}
int front_pop(int* frontstack)
{
	return frontstack[fronthead--];
}
int back_pop(int* backstack)
{
	return backstack[backhead--];
}

int front_top(int* frontstack)
{
	return frontstack[fronthead];
}
int back_top(int* backstack)
{
	return backstack[backhead];
}

void clearfront(int* frontstack)
{
	fronthead = -1;
}

void clearback(int* backstack)
{
	backhead = -1;
}

void clearnew(int* newbackstack)
{
	newbackhead = -1;
	newbackheaddown = 0;
}

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);
	int temp = 0;
	int count = 0;
	for (int i = 0; i < num2; i++)
	{
		char command;
		scanf(" %c", &command);
		if (command == 'B')
		{
			if (backempty(backstack) == 0)
			{
				front_push(frontstack, temp);
				temp = back_pop(backstack);
			}
		}
		else if (command == 'F')
		{
			if (frontempty(frontstack) == 0)
			{
				back_push(backstack, temp);
				temp = front_pop(frontstack);
			}
		}
		else if (command == 'A')
		{
			int number = 0;
			clearfront(frontstack);
			scanf("%d", &number);
			if (count != 0)
			{	
				back_push(backstack, temp);
			}
			count++;
			temp = number;
		}
		else if (command == 'C')
		{
			if (backhead > 0)
			{
				backstack[backhead + 1] = 0;
				for (int j = 0; j <= backhead; j++)
				{
					if (backstack[j] != backstack[j + 1])
					{
						new_push(newbackstack, backstack[j]);
					}
				}
				clearback(backstack);
				while (emptynew(newbackstack) == 0)
				{
					back_push(backstack, new_pop(newbackstack));
				}
				clearnew(newbackstack);
			}	
		}
	}

	printf("%d\n", temp);
	if (backempty(backstack) == 1)
	{
		printf("-1\n");
	}
	else
	{
		for (int i = backhead; i >= 0; i--)
		{
			printf("%d ", backstack[i]);
		}
		printf("\n");
	}
	if (frontempty(frontstack) == 1)
	{
		printf("-1\n");
	}
	else
	{
		for (int i = fronthead; i >= 0; i--)
		{
			printf("%d ", frontstack[i]);
		}
		printf("\n");
	}
}