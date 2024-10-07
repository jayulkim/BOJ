#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int que[30005];

int headup = 14999;
int headdown = 15000;

void push(int* que, int num)
{
	que[++headup] = num;
}

int size(int* que)
{
	return headup - headdown + 1;
}

int empty(int* que)
{
	if (headup == headdown - 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int pop(int* que)
{
	if (empty(que) == 1)
	{
		return -1;
	}
	else
	{
		return que[headdown++];
	}
}

int front(int* que)
{
	if (empty(que) == 1)
	{
		return -1;
	}
	else
	{
		return que[headdown];
	}
	
}
int back(int* que)
{
	if (empty(que) == 1)
	{
		return -1;
	}
	else
	{
		return que[headup];
	}
}




int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		char str[10];
		scanf("%s", str);

		if (strcmp(str, "push") == 0)
		{
			int num2 = 0;
			scanf("%d", &num2);
			push(que, num2);
		}
		else if (strcmp(str, "pop") == 0)
		{
			printf("%d\n", pop(que));
		}
		else if (strcmp(str, "size") == 0)
		{
			printf("%d\n", size(que));
		}
		else if (strcmp(str, "empty") == 0)
		{
			printf("%d\n", empty(que));
		}
		else if (strcmp(str, "front") == 0)
		{
			printf("%d\n", front(que));
		}
		else if (strcmp(str, "back") == 0)
		{
			printf("%d\n", back(que));
		}
	}
}