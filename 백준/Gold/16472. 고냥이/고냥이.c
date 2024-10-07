#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

char str[100005];

int ary[30] = { 0, };

int main(void)
{
	//printf("%d", 'a');
	int num1 = 0;
	scanf("%d", &num1);
	scanf("%s", str);
	int num2 = strlen(str);

	int start = 0;
	int end = 0;
	int max = 0;

	while (end <= num2)
	{
		int count = 0;
		

		for (int i = 0; i <= 25; i++)
		{
			if (ary[i] != 0)
			{
				count++;
				//ary[i] = 0;
			}
		}
		//printf("%d\n", count);
		//printf("%d %d\n", start, end);
		if (count > num1)
		{
			ary[str[start] - 97]--;
			start++;
		}
		else
		{
			ary[str[end] - 97]++;
			if (max < end - start)
			{
				max = end - start;
			}
			end++;
		}
	}
	
	printf("%d\n", max);

}


