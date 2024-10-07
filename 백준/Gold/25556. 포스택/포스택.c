#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int ary[100005] = { 0, };
int stack1[100005];
int stack2[100005];
int stack3[100005];
int stack4[100005];

int head1 = -1;
int head2 = -1;
int head3 = -1;
int head4 = -1;

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
int empty2(int* stack2)
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
int empty3(int* stack3)
{
	if (head3 == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int empty4(int* stack4)
{
	if (head4 == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push1(int* stack1, int num)
{
	stack1[++head1] = num;
}
void push2(int* stack2, int num)
{
	stack2[++head2] = num;
}
void push3(int* stack3, int num)
{
	stack3[++head3] = num;
}
void push4(int* stack4, int num)
{
	stack4[++head4] = num;
}

int pop1(int* stack1)
{
	return stack1[head1--];
}
int pop2(int* stack2)
{
	return stack2[head2--];
}
int pop3(int** stack3)
{
	return stack3[head3--];
}
int pop4(int* stack4)
{
	return stack4[head4--];
}

int top1(int* stack1)
{
	return stack1[head1];
}
int top2(int* stack2)
{
	return stack2[head2];
}
int top3(int* stack3)
{
	return stack3[head3];
}
int top4(int* stack4)
{
	return stack4[head4];
}

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary[i]);
	}

	push1(stack1, ary[0]);
	//printf("%d", top1(stack1));
	for (int i = 1; i < num1; i++)
	{
		if (empty1(stack1) == 0)
		{
			if (top1(stack1) > ary[i])
			{
				if (empty2(stack2) == 1)
				{
					push2(stack2, ary[i]);
				}
				else
				{
					if (top2(stack2) < ary[i])
					{
						push2(stack2, ary[i]);
					}
					else
					{
						if (empty3(stack3) == 1)
						{
							push3(stack3, ary[i]);
						}
						else
						{
							if (top3(stack3) < ary[i])
							{
								push3(stack3, ary[i]);
							}
							else
							{
								if (empty4(stack4) == 1)
								{
									push4(stack4, ary[i]);
								}
								else
								{
									if (top4(stack4) < ary[i])
									{
										push4(stack4, ary[i]);
									}
									else
									{
										printf("NO\n");
										return 0;
									}
								}
							}
							
						}
					}
					
				}
			}
		}
	}

	printf("YES\n");

}
