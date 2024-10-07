#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int ary[10000] = { 0, };
char str[35];

char stack[35];
int head = -1;

char stack1[35];
int head1 = -1;
int empty1(char* stack1)
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
void push1(char* stack1, char str1)
{
	stack1[++head1] = str1;
}
char pop1(char* stack1)
{
	return stack1[head1--];
}
char top1(char* stack1)
{
	return stack1[head1];
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

void push(char* stack, char str)
{
	stack[++head] = str;
}

char pop(char* stack)
{
	return stack[head--];
}

char top(char* stack)
{
	return stack[head];
}

int main(void)
{
	scanf("%s", str);

	int num1 = strlen(str);

	int index = 0;
	int count1 = 0;

	for (int i = 0; i < num1; i++)
	{
		if (str[i] == '(' || str[i] == '[')
		{
			push(stack, str[i]);
		}
		else if (str[i] == ')')
		{
			if (i == 0)
			{
				printf("0\n");
				return 0;
			}
			else
			{
				if (empty(stack) == 1)
				{
					printf("0\n");
					return 0;
				}
				else
				{
					//printf("%c\n", top(stack));
					if (top(stack) == '(')
					{
						pop(stack);
						push(stack, '2');
						count1++;
						//printf("%d\n", ary[index]);
						
					}
					else if (top(stack) == '2' || top(stack) == '3')
					{
						push(stack, ')');
					}
					else
					{
						if (count1 != 0)
						{
							push(stack, ')');
						}
						else
						{
							//printf("%c\n", top(stack));
							printf("0\n");
							return 0;
						}	
					}
				}
			}
		}
		else if (str[i] == ']')
		{
			if (i == 0)
			{
				printf("0\n");
				return 0;
			}
			else
			{
				if (empty(stack) == 1)
				{
					printf("0\n");
					return 0;
				}
				else
				{
					if (top(stack) == '[')
					{
						pop(stack);
						push(stack, '3');
						count1++;
					}
					else if (top(stack) == '3' || top(stack) == '2')
					{
						push(stack, ']');
					}
					else
					{
						if (count1 != 0)
						{
							push(stack, ']');
						}
						else
						{
							printf("0\n");
							return 0;
						}
					}
				}

			}
		}
	}
	for (int i = 0; i <= head; i++)
	{
		//printf("%c", stack[i]);
		if (stack[i] == '(' || stack[i] == '[')
		{
			push1(stack1, stack[i]);
		}
		else if (stack[i] == '2')
		{
			ary[index] = 2;
			for (int j = 0; j <= head1; j++)
			{
				if (stack1[j] == '(')
				{
					ary[index] *= 2;
				}
				else if (stack1[j] == '[')
				{
					ary[index] *= 3;
				}
				else
				{
					printf("0\n");
					return 0;
				}
			}
			index++;
		}
		else if (stack[i] == '3')
		{
			ary[index] = 3;
			for (int j = 0; j <= head1; j++)
			{
			//	printf("%c", stack1[j]);
				if (stack1[j] == '(')
				{
					ary[index] *= 2;
				}
				else if (stack1[j] == '[')
				{
					ary[index] *= 3;
				}
				else
				{
					printf("0\n");
					return 0;
				}
			}
			index++;
		}
		else if (stack[i] == ')')
		{
			if (empty1(stack1) == 1)
			{
				printf("0\n");
				return 0;
			}
			else
			{
				if (top1(stack1) == '(')
				{
					pop1(stack1);
				}
				else
				{
					printf("0\n");
					return 0;
				}
			}
		}
		else if (stack[i] == ']')
		{
			if (empty1(stack1) == 1)
			{
				printf("0\n");
				return 0;
			}
			else
			{
				if (top1(stack1) == '[')
				{
					pop1(stack1);
				}
				else
				{
					printf("0\n");
					return 0;
				}
			}
		}

	}
	
	if (empty1(stack1) == 1)
	{
		long long int sum = 0;
		for (int i = 0; i < index; i++)
		{
			sum += ary[i];
		}
		printf("%lld\n", sum);
	}
	else
	{
		printf("0\n");
		return 0;
	}

}
