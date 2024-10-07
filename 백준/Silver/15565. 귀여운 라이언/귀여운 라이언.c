#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int ary[1000005] = { 0, };
int ary1[1000005] = { 0, };

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int count1 = 0;
	scanf("%d %d", &num1, &num2);
	int index = 0;
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary[i]);
		if (ary[i] == 1)
		{
			ary1[index] = i;
			//printf("%d ", ary1[index]);
			index++;
			count1++;
		}
	}
	if (count1 < num2)
	{
		printf("-1\n");
		return 0;
	}
	

	
	int min = 1000005;

	int start = 0;
	int end = start + num2 - 1;

	while (end < index)
	{
		if (ary1[end] - ary1[start] + 1 < min)
		{
			min = ary1[end] - ary1[start] + 1;
		}
		start++;
		end++;
	}


	printf("%d\n", min);

}