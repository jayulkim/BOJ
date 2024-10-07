#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <memory.h>

int ary[55] = { 0, };
int ary1[10005] = { 0, };

int stack[10005] = { 0, };
int stack1[10005] = { 0, };

int head = -1;
int head1 = -1;

int compare(const void* num1, const void* num2)
{
	int a = *(int*)num1;
	int b = *(int*)num2;
	if (a > b)
	{
		return -1;
	}
	else if (a < b)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int empty(int* stack)
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

void push(int* stack, int num)
{
	stack[++head] = num;
}

int pop(int* stack)
{
	return stack[head--];
}

void clear(int* stack)
{
	head = -1;
}

void clear1(int* stack1)
{
	head1 = -1;
}
int top(int* stack)
{
	return stack[head];
}

int top1(int* stack1)
{
	return stack1[head1];
}

int empty1(int* stack1)
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

void push1(int* stack1, int num1)
{
	stack1[++head1] = num1;
}

int pop1(int* stack1)
{
	return stack1[head1--];
}

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary[i]);
	}
	int num2 = 0;
	scanf("%d", &num2);
	for (int i = 0; i < num2; i++)
	{
		scanf("%d", &ary1[i]);
	}
	qsort(ary, num1, sizeof(int), compare);
	qsort(ary1, num2, sizeof(int), compare);

	if (ary[0] < ary1[0])
	{
		printf("-1\n");
		return 0;
	}

	int count = 1;

	int index = 0;
	int count1 = 0;
	for (int i = 0; i < num2; i++)
	{
		push(stack, ary1[i]);
		if (top(stack) <= ary[index])
		{
			if (count1 == 0)
			{
				pop(stack);
				index++;
			}
			else
			{
				push(stack, ary1[i]);
			}
		}
		if (index == num1)
		{
			count1++;
		}
	}
	if (empty(stack) == 1)
	{
		printf("%d\n", count);
		return 0;
	}
	else
	{
		count++;
	}
	for (int i = 0; i <= head; i++)
	{
	//	printf("%d ", stack[i]);
	}
	//printf("\n");
	int choice = 0;
	
	while (1)
	{
		int count2 = 0;
		int count3 = 0;
		int index1 = 0;
		int index2 = 0;
		if (choice == 0)
		{	
			for (int i = 0; i <= head; i++)
			{
				push1(stack1, stack[i]);
				if (top1(stack1) <= ary[index1])
				{
					if (count2 == 0)
					{
						pop1(stack1);
						index1++;
					}
					else
					{
						push(stack1, stack[i]);
					}
				}
				if (index1 == num1)
				{	
					count2++;
				}
			}
			for (int i = 0; i <= head1; i++)
			{
				//printf("%d ", stack1[i]);
			}
			//printf("\n");
			choice++;
			
			clear(stack);
			if (empty1(stack1) == 1)
			{
				//printf("11\n");
				break;
			}
			else
			{
				count++;
			}
		}
		else
		{
			for (int i = 0; i <= head1; i++)
			{
				push(stack, stack1[i]);
				if (top(stack) <= ary[index2])
				{
					if (count3 == 0)
					{
						pop(stack);
						index2++;
					}
					else
					{
						push(stack, stack1[i]);
					}
				}
				if (index2 == num1)
				{
					count3++;
				}
			}
			for (int i = 0; i <= head; i++)
			{
				//printf("%d ", stack[i]);
			}
		//	printf("\n");
			choice--;
			
			clear1(stack1);
			if (empty(stack) == 1)
			{
				//printf("22\n");
				break;
			}
			else
			{
				count++;
			}
		}
		
	}
	for (int i = 0; i <= head; i++)
	{
		//printf("%d ", stack[i]);
	}
	
	printf("%d\n", count);
	

}