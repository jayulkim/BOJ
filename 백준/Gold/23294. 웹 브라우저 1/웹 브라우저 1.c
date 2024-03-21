#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int backkash = 0;
int frontkash = 0;

int temp = 0;

int backstack[20005] = { 0, };
int frontstack[20005] = { 0, };
int newbackstack[20005] = { 0, };
int backhead = -1;
int backheaddown = 0;
int fronthead = -1;
int newbackhead = -1;
int newbackheaddown = 0;

int emptybackstack()
{
	if (backheaddown - 1 == backhead)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int emptyfrontstack()
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

int emptynewbackstack()
{
	if (newbackhead == newbackheaddown - 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void pushbackstack(int* backstack, int num)
{
	backstack[++backhead] = num;
}

void pushfrontstack(int* frontstack, int num)
{
	frontstack[++fronthead] = num;
}

void pushnewbackstack(int* newbackstack, int num)
{
	newbackstack[++newbackhead] = num;
}

int popbackstack(int* backstack)
{
	return backstack[backhead--];
}

int popbackstackdown(int* backstack)
{
	return backstack[backheaddown++];
}

int popfrontstack(int* frontstack)
{
	return frontstack[fronthead--];
}

int popnewbackstack(int* newbackstack)
{
	return newbackstack[newbackheaddown++];
}

void clearbackstack()
{
	backhead = -1;
	backheaddown = 0;
}

void clearfrontstack()
{
	fronthead = -1;
}

void clearnewbackstack()
{
	newbackhead = -1;
	newbackheaddown = 0;
}

int space[20005] = { 0, };

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	scanf("%d %d %d", &num1, &num2, &num3);
	for (int i = 1; i <= num1; i++)
	{
		scanf("%d", &space[i]);
	}

	int first = 0;
	for (int i = 0; i < num2; i++)
	{
		char command;
		scanf(" %c", &command);
		if (command == 'B')
		{
			if (emptybackstack() == 0)
			{
				pushfrontstack(frontstack, temp);
				frontkash += space[temp];
				temp = popbackstack(backstack);
				backkash -= space[temp];
			}
		}
		else if (command == 'F')
		{
			if (emptyfrontstack() == 0)
			{
				pushbackstack(backstack, temp);
				backkash += space[temp];
				temp = popfrontstack(frontstack);
				frontkash -= space[temp];
			}
		}
		else if (command == 'A')
		{
			int number = 0;
			scanf("%d", &number);
			clearfrontstack();
			frontkash = 0;
			if (first != 0)
			{
				pushbackstack(backstack, temp);
				backkash += space[temp];
			}
			first++;
			temp = number;
			if (num3 < backkash + frontkash + space[temp])
			{
				while (num3 < backkash + frontkash + space[temp] && emptybackstack() == 0)
				{
					backkash -= space[popbackstackdown(backstack)];
				}
			}
		}
		else if (command == 'C')
		{
			backstack[backhead + 1] = 0;
			int newbackkash = 0;
			for (int j = backheaddown; j <= backhead; j++)
			{
				if (backstack[j] != backstack[j + 1])
				{
					pushnewbackstack(newbackstack, backstack[j]);
					newbackkash += space[backstack[j]];
				}
			}
			clearbackstack();
			while (emptynewbackstack() == 0)
			{
				pushbackstack(backstack, popnewbackstack(newbackstack));
			}
			clearnewbackstack();
			backkash = newbackkash;
		}
	//	printf("%d\n", backkash + frontkash + space[temp]);
	}
	printf("%d\n", temp);
	if (emptybackstack() == 1)
	{
		printf("-1\n");
	}
	else
	{
		for (int i = backhead; i >= backheaddown; i--)
		{
			printf("%d ", backstack[i]);
		}
		printf("\n");
	}
	if (emptyfrontstack() == 1)
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

