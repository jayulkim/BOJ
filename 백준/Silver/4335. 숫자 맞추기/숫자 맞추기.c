#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ary[5] = { 0, 11,};

int main(void)
{
	while (1)
	{
		int num1 = 0;
		scanf("%d", &num1);
		if (num1 == 0)
		{
			break;
		}
		char str[5][10];

		scanf("%s %s", str[0], str[1]);

		if (strcmp(str[0], "too") == 0 && strcmp(str[1], "high") == 0)
		{

			if (num1 < ary[1])
			{
				ary[1] = num1;
			}
		}
		else if (strcmp(str[0], "too") == 0 && strcmp(str[1], "low") == 0)
		{
			if (ary[0] < num1)
			{
				ary[0] = num1;
			}	
		}
		else if (strcmp(str[0], "right") == 0 && strcmp(str[1], "on") == 0)
		{
			if (ary[0] < num1 && ary[1] > num1)
			{
				printf("Stan may be honest\n");
			}
			else
			{
				printf("Stan is dishonest\n");
			}
			ary[0] = 0;
			ary[1] = 11;
		}
		

	}

}