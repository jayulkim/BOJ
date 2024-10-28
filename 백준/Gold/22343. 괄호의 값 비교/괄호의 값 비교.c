#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack1[3000005];
char stack2[3000005];
int head1 = -1;
int head2 = -1;

int empty1()
{
	if (head1 == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int empty2()
{
	if (head2 == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void push1(char* stack1, char str)
{
	stack1[++head1] = str;
}
void push2(char* stack2, char str)
{
	stack2[++head2] = str;
}
char pop1(char* stack1)
{
	return stack1[head1--];
}
char pop2(char* stack2)
{
	return stack2[head2--];
}
char str1[3000005];
char str2[3000005];
int ary[3000005] = { 0, };
int ary1[3000005] = { 0, };
int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		int index = 0;
		int start = 0;
		scanf("%s", str1);
		scanf("%s", str2);
		int num2 = strlen(str1);
		int num3 = strlen(str2);
		for (int j = 0; j < num2; j++)
		{	
			if (str1[j] == ')')
			{
				pop1(stack1);
				if (start == 0)
				{
					ary[index] = 1;
					start++;
				}
				else
				{
					ary[index] *= 2;
				}
				if (empty1() == 1)
				{
					start = 0;
					index++;
				}
			}
			else
			{
				push1(stack1, str1[j]);
			}
		}
		int index1 = 0;
		int start1 = 0;
		for (int j = 0; j < num3; j++)
		{
			if (str2[j] == ')')
			{
				pop2(stack2);
				if (start1 == 0)
				{
					ary1[index1] = 1;
					start1++;
				}
				else
				{
					ary1[index1] *= 2;
				}
				if (empty2() == 1)
				{
					start1 = 0;
					index1++;
				}
			}
			else
			{
				push2(stack2, str2[j]);
			}
		}
		int sum = 0;
		int sum1 = 0;
		for (int j = 0; j < index; j++)
		{
			sum += ary[j];
		}
		for (int j = 0; j < index1; j++)
		{
			sum1 += ary1[j];
		}
		if (sum == sum1)
		{
			printf("=\n");
		}
		else if (sum < sum1)
		{
			printf("<\n");
		}
		else if (sum > sum1)
		{
			printf(">\n");
		}
		head1 = -1;
		head2 = -1;
	}
}