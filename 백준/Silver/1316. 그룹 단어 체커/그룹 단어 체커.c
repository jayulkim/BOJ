#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int num1 = 0;

	int result = 0;

	
	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		char str1[100];
		scanf("%s", str1);

		int num2 = strlen(str1);
		int ary1[100] = { 0, };
		int ary2[30] = { 0, };
		int count1 = 0;
		int count2 = 0;

		int index = 0;
		int num3 = 0;
		for (int j = 0; j < num2; j++)
		{
			if (str1[j] == 'a')
			{
				ary2[0]++;
			}
			else if (str1[j] == 'b')
			{
				ary2[1]++;
			}
			else if (str1[j] == 'c')
			{
				ary2[2]++;
			}
			else if (str1[j] == 'd')
			{
				ary2[3]++;
			}
			else if (str1[j] == 'e')
			{
				ary2[4]++;
			}
			else if (str1[j] == 'f')
			{
				ary2[5]++;
			}
			else if (str1[j] == 'g')
			{
				ary2[6]++;
			}
			else if (str1[j] == 'h')
			{
				ary2[7]++;
			}
			else if (str1[j] == 'i')
			{
				ary2[8]++;
			}
			else if (str1[j] == 'j')
			{
				ary2[9]++;
			}
			else if (str1[j] == 'k')
			{
				ary2[10]++;
			}
			else if (str1[j] == 'l')
			{
				ary2[11]++;
			}
			else if (str1[j] == 'm')
			{
				ary2[12]++;
			}
			else if (str1[j] == 'n')
			{
				ary2[13]++;
			}
			else if (str1[j] == 'o')
			{
				ary2[14]++;
			}
			else if (str1[j] == 'p')
			{
				ary2[15]++;
			}
			else if (str1[j] == 'q')
			{
				ary2[16]++;
			}
			else if (str1[j] == 'r')
			{
				ary2[17]++;
			}
			else if (str1[j] == 's')
			{
				ary2[18]++;
			}
			else if (str1[j] == 't')
			{
				ary2[19]++;
			}
			else if (str1[j] == 'u')
			{
				ary2[20]++;
			}
			else if (str1[j] == 'v')
			{
				ary2[21]++;
			}
			else if (str1[j] == 'w')
			{
				ary2[22]++;
			}
			else if (str1[j] == 'x')
			{
				ary2[23]++;
			}
			else if (str1[j] == 'y')
			{
				ary2[24]++;
			}
			else if (str1[j] == 'z')
			{
				ary2[25]++;
			}
		}
		for (int k = 0; k < num2 - 1; k++)
		{
			ary1[index]++;
			if (str1[k] != str1[k + 1])
			{
				index++;
			}
			else
			{
				num3++;
			}

		}
		if (num3 == 0)
		{
			count1++;
		}
		if (num3 != 0 && str1[num2 - 1] != str1[num2 - 2])
		{
			count1++;
		}
		for (int j = 0; j < num2; j++)
		{
			if (ary1[j] != 0)
			{
				count1++;
			}
			
		}
		for (int j = 0; j < 26; j++)
		{
			if (ary2[j] != 0)
			{
				count2++;
			}
		}
		if (count1 == count2)
		{
			result++;
		}
	}
	printf("%d", result);

	


}