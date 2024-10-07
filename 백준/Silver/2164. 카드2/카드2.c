#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[1600005] = { 0, };
int headup = 599999;
int headdown = 600000;

void pushup(int* stack, int num)
{
	stack[++headup] = num;
}

int popup(int* stack)
{
	return stack[headup--];
}

void pushdown(int* stack, int num)
{
	stack[--headdown] = num;
}

int top(int* stack)
{
	return stack[headup];
}

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	for (int i = num1; i >= 1; i--)
	{
		pushup(stack, i);
	}

	while (headup > headdown)
	{
		popup(stack);

		pushdown(stack, top(stack));

		popup(stack);
	}
	printf("%d\n", top(stack));
	
}