#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int deak[2000005] = { 0, };
int headup = 999999;
int headdown = 1000000;

int empty(int* deak)
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

void push_front(int* deak, int num)
{
	deak[--headdown] = num;
}

void push_back(int* deak, int num)
{
	deak[++headup] = num;
}

int pop_front(int* deak)
{
	if (empty(deak) == 1)
	{
		return -1;
	}
	else
	{
		return deak[headdown++];
	}
}

int pop_back(int* deak)
{
	if (empty(deak) == 1)
	{
		return -1;
	}
	else
	{
		return deak[headup--];
	}
}

int size(int* deak)
{
	return headup - headdown + 1;
}

int front(int* deak)
{
	if (empty(deak) == 1)
	{
		return -1;
	}
	else
	{
		return deak[headdown];
	}
	
}

int back(int* deak)
{
	if (empty(deak) == 1)
	{
		return -1;
	}
	else
	{
		return deak[headup];
	}
	
}

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		char str[20];
		scanf("%s", str);

		if (strcmp(str, "1") == 0)
		{
			int num2 = 0;
			scanf("%d", &num2);
			push_front(deak, num2);
		}
		else if (strcmp(str, "2") == 0)
		{
			int num3 = 0;
			scanf("%d", &num3);
			push_back(deak, num3);
		}
		else if (strcmp(str, "3") == 0)
		{
			printf("%d\n", pop_front(deak));
		}
		else if (strcmp(str, "4") == 0)
		{
			printf("%d\n", pop_back(deak));
		}
		else if (strcmp(str, "5") == 0)
		{
			printf("%d\n", size(deak));
		}
		else if (strcmp(str, "6") == 0)
		{
			printf("%d\n", empty(deak));
		}
		else if (strcmp(str, "7") == 0)
		{
			printf("%d\n", front(deak));
		}
		else if (strcmp(str, "8") == 0)
		{
			printf("%d\n", back(deak));
		}
	
	}

}