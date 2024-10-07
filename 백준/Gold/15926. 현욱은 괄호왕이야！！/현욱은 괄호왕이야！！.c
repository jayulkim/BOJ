#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ary[200005] = { 0, };

int ary1[200005] = { 0, };
char str[200005];
char stack[200005];
int head = -1;

char stack1[200005];
int head1 = 200001;

int empty1(char* stack1)
{
	if (head1 == 200001)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

char pop1(char* stack1)
{
	return stack1[head1++];
}

void push1(char* stack1, char str1)
{
	stack1[--head1] = str1;
}



int empty(char* stack)
{
	if (head == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

char pop(char* stack)
{
	return stack[head--];
}

void push(char* stack, char str)
{
	stack[++head] = str;
}

int compare(const void* num1, const void* num2)
{
	int a = *(int*)num1;
	int b = *(int*)num2;
	if (a > b)
	{
		return 1;
	}
	else if (a < b)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	scanf("%s", str);
	
	int index = 0;
	for (int i = 0; i < num1; i++)
	{
		
		if (str[i] == '(')
		{
			push(stack, str[i]);
		}
		else if (str[i] == ')')
		{
			if (i != 0 && empty(stack) == 0)
			{
				ary[i] = 1;
				pop(stack);
			}
			
		}

	}
	for (int i = num1 - 1; i >= 0; i--)
	{

		if (str[i] == ')')
		{
			push1(stack1, str[i]);
		}
		else if (str[i] == '(')
		{
			if (i != num1 - 1 && empty1(stack1) == 0)
			{
				ary[i] = 1;
				pop1(stack1);
			}


		}

	}

	for (int i = 0; i < num1; i++)
	{
	//	printf("%d", ary[i]);
		if (ary[i] == 1)
		{
			ary1[index]++;
		}
		else
		{
			index++;
		}
	}
	qsort(ary1, index + 1, sizeof(int), compare);
	printf("%d\n", ary1[index]);
}

