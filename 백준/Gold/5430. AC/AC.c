#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <memory.h>

char str[1000005];

char str1[1000005];
int stack[1000005] = { 0, };
int headup = -1;
int headdown = 0;

int empty(int* stack)
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

int popup(int* stack)
{
	return stack[headup--];
}
int popdown(int* stack)
{
	return stack[headdown++];
}

void push(int* stack, int num)
{
	stack[++headup] = num;
}

int main(void)
{
	//scanf("%s", str);
	//int num5 = strlen(str);
	//for (int i = 0; i < num5; i++)
	//{
	//	if (isdigit(str[i]) != 0)
	//	{
			//printf("%c ", str[i]);
		//}
//	}
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		scanf("%s", str);
		int num2 = strlen(str);
		
		int num3 = 0;
		scanf("%d", &num3);
		scanf("%s", str1);
		int num4 = strlen(str1);

		for (int j = 0; j < num4; j++)
		{
			int index1 = 0;
			if (str1[j] == '[' || str1[j] == ',')
			{
				push(stack, atoi(&str1[j + 1]));
			//	printf("%d ", stack[headup]);
			}
		}
		
		int count = 0;
		int count1 = 0;
		int count2 = 0;
		for (int j = 0; j < num2; j++)
		{
			
			if (str[j] == 'R')
			{
				if (count == 0)
				{
					count++;
				}
				else
				{
					count--;
				}			
			}
			else if (str[j] == 'D')
			{
				count2++;
				if (count == 1)
				{
					if (empty(stack) == 1)
					{
						printf("error\n");
						count1++;
						break;
					}
					popup(stack);
				}
				else
				{
					if (empty(stack) == 1)
					{
						printf("error\n");
						count1++;
						break;
					}
					popdown(stack);
				}
			}

		}
		if (count1 == 0)
		{
			if (stack[headup] == 0)
			{
				if (count2 != 0)
				{
					if (stack[headup] == 0)
					{
						count1++;
						printf("error\n");
					}
				}
				else
				{
					count1++;
					printf("[]\n");
				}
			}
		}
		
	//	printf("%d %d\n", count, count1);
		if (count1 == 0)
		{
			printf("[");
			if (count == 0)
			{
				for (int j = headdown; j <= headup; j++)
				{
					if (j == headup)
					{
						printf("%d", stack[j]);
					}
					else
					{
						printf("%d,", stack[j]);
					}				
				}
			}
			else 
			{
				for (int j = headup; j >= headdown; j--)
				{
					if (j == headdown)
					{
						printf("%d", stack[j]);
					}
					else
					{
						printf("%d,", stack[j]);
					}
				}
			}
			printf("]\n");
		}

		for (int j = 0; j <= headup; j++)
		{
			//printf("%d\n", stack[j]);
		}
		headup = -1;
		headdown = 0;

	}




}