#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void swap(int* a, int* b)
{
	int c = *b;
	*b = *a;
	*a = c;
}


int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int num4 = 0;

	scanf("%d %d", &num1, &num2);
	int* p = (int*)malloc(sizeof(int) * num1);

	for (int i = 0; i < num1; i++)
	{
		p[i] = i + 1;

	}

	for (int i = 0; i < num2; i++)
	{
		scanf("%d %d", &num3, &num4);
		if (num3 != num4)
		{
			if ((num4 - num3) % 2 == 0)
			{
				for (int j = 0; j < (num4 - num3) / 2; j++)
				{
					swap(&p[num3 + j - 1], &p[num4 - j - 1]);
				}
			}
			if ((num4 - num3) % 2 != 0)
			{
				for (int j = 0; j < ((num4 - num3) / 2) + 1; j++)
				{
					swap(&p[num3 + j - 1], &p[num4 - j - 1]);
				}
			}
		}
	
	}
	for (int i = 0; i < num1; i++)
	{
		printf("%d ", p[i]);
	}
}