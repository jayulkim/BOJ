#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

char str[100005];

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		scanf("%s", str);
		int num2 = strlen(str);

		int start = 0;
		int end = num2 - 1;

		int count1 = 0;
		int count2 = 0;

		while (start < end)
		{
			if (str[start] != str[end])
			{
				count1++;
				end--;
			}
			else
			{
				start++;
				end--;
			}
		}
		int start1 = 0;
		int end1 = num2 - 1;
		while (start1 < end1)
		{
			if (str[start1] != str[end1])
			{
				count2++;
				start1++;
			}
			else
			{
				start1++;
				end1--;
			}
		}
		//printf("%d %d\n", count1, count2);
		if (count1 == 0 && count2 == 0)
		{
			printf("0\n");
		}
		else if (count1 == 1 || count2 == 1)
		{
			printf("1\n");
		}
		else if (count1 > 1 && count2 > 1)
		{
			printf("2\n");
		}
	}
	
	



}