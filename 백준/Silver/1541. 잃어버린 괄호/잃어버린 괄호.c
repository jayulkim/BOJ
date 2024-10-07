#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

char str[555];

int ary[1000000];

int main(void)
{
	//	printf("%c", 48 + 1);
	scanf("%s", str);
	int num1 = strlen(str);

	int index1 = 0;
	for (int i = 0; i < num1; i++)
	{
		if (str[i] == '-')
		{
			for (int j = i + 1; j <= num1; j++)
			{
				if (str[j] == '+')
				{
					str[j] = '-';
				}
			}
		}
	}
	char str2[555];
	int index2 = 0;
	int index = 0;
	for (int i = 0; i <= num1; i++)
	{
		
		if (str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9')
		{
			str2[index] = str[i];
			index++;
		}
		else if (str[i] == '-' || str[i] == '+' || str[i] == '\0')
		{
			int num2 = atoi(str2);

			ary[index1] = num2;
			index1++;
			index2 = i;
			break;
		}
	}
	char str3[555];
	for (int i = index2; i < num1; i++)
	{
		
		int index3 = 0;
		if (str[i] == '-')
		{
			for (int j = i + 1; j <= num1; j++)
			{
				if (str[j] == '0' || str[j] == '1' || str[j] == '2' || str[j] == '3' || str[j] == '4' || str[j] == '5' || str[j] == '6' || str[j] == '7' || str[j] == '8' || str[j] == '9')
				{
					str3[index3] = str[j];
					index3++;
				}
				else if (str[j] == '+' || str[j] == '-' || str[j] == '\0')
				{
					int num4 = atoi(str3);
					//printf("%d\n", num3);
					ary[index1] = -num4;
					index1++;
					for (int k = 0; k <= index3; k++)
					{
						str3[k] = '\0';
					}
					break;
				}
			}
			//	printf("%s\n", str3);
		}
		else if (str[i] == '+')
		{
			for (int j = i + 1; j <= num1; j++)
			{
				if (str[j] == '0' || str[j] == '1' || str[j] == '2' || str[j] == '3' || str[j] == '4' || str[j] == '5' || str[j] == '6' || str[j] == '7' || str[j] == '8' || str[j] == '9')
				{
					str3[index3] = str[j];
					index3++;
				}
				else if (str[j] == '+' || str[j] == '-' || str[j] == '\0')
				{
					int num3 = atoi(str3);
					ary[index1] = num3;
					index1++;
					for (int k = 0; k <= index3; k++)
					{
						str3[k] = '\0';
					}
					break;
				}
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < index1; i++)
	{
		//	printf("%d ", ary[i]);
		sum += ary[i];
	}
	printf("%d\n", sum);

}

