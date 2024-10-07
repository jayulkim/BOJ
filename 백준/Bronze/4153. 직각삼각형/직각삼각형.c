#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	while (1)
	{
		int ary[10] = { 0, };

		scanf("%d", &ary[0]);
		scanf("%d", &ary[1]);
		scanf("%d", &ary[2]);
		if (ary[0] == 0 && ary[1] == 0 && ary[2] == 0)
		{
			break;
		}
		else
		{
			qsort(ary, 3, sizeof(int), compare);

			if (ary[0] * ary[0] + ary[1] * ary[1] == ary[2] * ary[2])
			{
				printf("right\n");
			}
			else
			{
				printf("wrong\n");
			}
		}
		


	}


}