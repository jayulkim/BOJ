#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[100];
char num1[10];
char num2[10];

int main(void)
{
	scanf("%s", str);
	int num3 = strlen(str);
	int count = 0;
	int index = -1;
	for (int i = 0; i < num3; i++)
	{
		if (str[i] == 'x')
		{
			index = i;
			count++;
			break;
		}
		num1[i] = str[i];
	}
	if (count != 0)
	{
		//printf("%s ", num1);
		int index1 = 0;
		if (str[index + 1] == '+')
		{
			for (int i = index + 2; i < num3; i++)
			{
				num2[index1] = str[i];
				index1++;
			}
			int head1 = atoi(num1);
			int end = atoi(num2);

			if (head1 /2!= 1 && head1/2 != -1)
			{
				if (end != 1)
				{
					printf("%dxx+%dx+W", head1 / 2, end);
				}
				else if (end == 1)
				{
					printf("%dxx+x+W", head1 / 2);
				}
			}
			else
			{
				if (head1/2 == -1)
				{
					if (end != 1)
					{
						printf("-xx+%dx+W", end);
					}
					else if (end == 1)
					{
						printf("-xx+x+W");
					}
				}
				else if (head1/2 == 1)
				{
					if (end != 1)
					{
						printf("xx+%dx+W", end);
					}
					else if (end == 1)
					{
						printf("xx+x+W");
					}
				}
			}
		}
		else if (str[index + 1] == '-')
		{
			for (int i = index + 2; i < num3; i++)
			{
				num2[index1] = str[i];
				index1++;
			}
			int head2 = atoi(num1);
			int end1 = atoi(num2);

			if (head2/2 != 1 && head2/2 != -1)
			{
				if (end1 != 1)
				{
					printf("%dxx-%dx+W", head2 / 2, end1);
				}
				else if (end1 == 1)
				{
					printf("%dxx-x+W", head2 / 2);
				}
			}
			else
			{
				if (head2 /2== -1)
				{
					if (end1 != 1)
					{
						printf("-xx-%dx+W", end1);
					}
					else if (end1 == 1)
					{
						printf("-xx-x+W");
					}
				}
				else if (head2/2 == 1)
				{
					if (end1 != 1)
					{
						printf("xx-%dx+W", end1);
					}
					else if (end1 == 1)
					{
						printf("xx-x+W");
					}
				}
			}
		}
		else if (str[num3 - 1] == 'x')
		{
			int head = atoi(num1);
			if (head/2 != 1 && head /2!= -1)
			{
				printf("%dxx+W", head / 2);
			}
			else
			{
				if (head /2== -1)
				{
					printf("-xx+W");
				}
				else if (head/2 == 1)
				{
					printf("xx+W");
				}
			}
			
		}
		//printf("%s", num2);

	}
	else
	{
		int head3 = atoi(num1);
		if (head3 == 0)
		{
			printf("W");
		}
		else
		{
			if (head3 != 1 && head3 != -1)
			{
				printf("%dx+W", head3);
			}
			else
			{
				if (head3 == 1)
				{
					printf("x+W");
				}
				else if (head3 == -1)
				{
					printf("-x+W");
				}
			}
		}
	
	}
	
}