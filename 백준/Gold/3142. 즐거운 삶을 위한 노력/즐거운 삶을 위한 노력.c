#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[1000005] = { 0, };
int prime[100005] = { 0, };
long long int sum[1000005] = { 0, };

int stack[1000005] = { 0, };
int head = -1;
int empty()
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

int main(void)
{
	for (int i = 2; i * i <= 1000000; i++)
	{
		if (ary[i] == 0)
		{
			for (int j = i * i; j <= 1000000; j += i)
			{
				ary[j] = 1;
			}
		}
	}
	int index = 0;
	for (int i = 2; i <= 1000; i++)
	{
		if (ary[i] == 0)
		{
			prime[index] = i;
			index++;
		}
	}

	int num1 = 0;
	scanf("%d", &num1);
	int count1 = 0;
	for (int j = 0; j < num1; j++)
	{
		int num2 = 0;
		scanf("%d", &num2);
		int index1 = 0;
		int count = 0;
		while (num2 > 1)
		{
			if (num2 % prime[index1] == 0)
			{
				sum[prime[index1]]++;
				num2 /= prime[index1];
			}
			else
			{
				index1++;
			}
			if (index1 >= index)
			{
				sum[num2]++;
				if (sum[num2] % 2 == 0)
				{
					if (stack[num2] == 1)
					{
						count1--;
						stack[num2] = 0;
					}
				}
				else
				{
					count1++;
					stack[num2] = 1;
				}
				break;
			}
		}
		for (int i = 0; i < index; i++)
		{
			//printf("%d ", sum[prime[i]]);
			if (sum[prime[i]] % 2 == 1)
			{
				count++;
				break;
			}
		}
		if (count1 != 0)
		{
			printf("NE\n");
		}
		else
		{
			if (count == 0)
			{
				printf("DA\n");
			}
			else
			{
				printf("NE\n");
			}
		}
	}
}
