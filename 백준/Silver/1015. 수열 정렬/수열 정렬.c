#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int ary[60] = { 0, };
int ary1[60] = { 0, };

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

	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary[i]);
		ary1[i] = ary[i];
	}
	qsort(ary, num1, sizeof(int), compare);
	int index = 0;
	for (int i = 0; i < num1; i++)
	{
		
		for (int j = 0; j < num1; j++)
		{
			if (ary1[i] == ary[j])
			{
			//	printf("111\n");
				index = j;
				ary[index] = 0;
				break;
			}
		}
		printf("%d ", index);
		
	}

}
