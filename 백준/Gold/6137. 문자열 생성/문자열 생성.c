#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char str[2005];
char result[2005];

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		scanf(" %c", &str[i]);
	}
	int start = 0;
	int end = num1 - 1;
	int index = 0;
	while (start <= end)
	{
		if (start == end)
		{
			result[index] = str[start];
			index++;
			break;
		}
		if (str[start] < str[end])
		{
			result[index] = str[start];
			index++;
			start++;
		}
		else if (str[start] > str[end])
		{
			result[index] = str[end];
			index++;
			end--;
		}
		else
		{
			int start1 = start + 1;
			int end1 = end - 1;
			int count = 0;
			if (start1 < end1)
			{
				while (start1 < end1)
				{
					if (str[start1] < str[end1])
					{
						result[index] = str[start];
						index++;
						start++;
						count++;
						break;
					}
					else if (str[start1] > str[end1])
					{
						result[index] = str[end];
						index++;
						end--;
						count++;
						break;
					}
					else
					{
						start1++;
						end1--;
					}
				}
				if (count == 0)
				{
					result[index] = str[start];
					index++;
					start++;
				}
			}
			else
			{
				result[index] = str[start];
				index++;
				start++;		
			}
		}
		
	}
	for (int i = 0; i < index; i++)
	{
		if (i % 80 == 0 && i != 0)
		{
			printf("\n");
		}
		printf("%c", result[i]);
	}
}