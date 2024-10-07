#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[100005] = { 0, };
int ary1[100005] = { 0, };

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
	}
	qsort(ary, num1, sizeof(int), compare);


	if (num1 % 2 == 0)
	{
		int index1 = 0;
		int count1 = 0;
		for (int i = 0; i < num1; i++)
		{
			if (ary[i] != ary[i + 1])
			{	
				index1++;
			}
			else
			{
				ary1[index1]++;
			}
		}
		for (int i = 0; i < index1; i++)
		{
			ary1[i]++;
			if (ary1[i] >= num1 / 2 + 1)
			{
				count1++;
				break;
			}
		}
		if (count1 == 0)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}


	}
	else if (num1 % 2 == 1)
	{
		int index2 = 0;
		int count2 = 0;
		for (int i = 0; i < num1; i++)
		{
			if (ary[i] != ary[i + 1])
			{
				index2++;
			}
			else
			{
				ary1[index2]++;
			}
		}
		for (int i = 0; i < index2; i++)
		{
			ary1[i]++;
			//printf("%d ", ary1[i]);
			if (ary1[i] >= num1 / 2 + 2)
			{
				count2++;
				break;
			}
		}
		if (count2 == 0)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}

	



}