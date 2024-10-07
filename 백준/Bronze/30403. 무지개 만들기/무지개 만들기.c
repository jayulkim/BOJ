#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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

int search(long long int* ary, int size, long long int key)
{
	int start = 0, end = size - 1;
	while (start <= end)
	{
		int cen = (start + end) / 2;

		if (ary[cen] == key)
		{
			return cen;
		}
		else if (ary[cen] > key)
		{
			end = cen - 1;
		}
		else if (ary[cen] < key)
		{
			start = cen + 1;
		}
	}
	return -1;
}

int main(void)
{
	char str1[100];

	int num2 = 0;
	scanf("%d", &num2);

	char str2[100];
	char str3[100];

	char str4[7];
	char str5[7];

	int count1 = 0;
	int count2 = 0;
	for (int i = 0; i < num2 + 1; i++)
	{
		scanf("%c", &str1[i]);
		if (islower(str1[i]))
		{
			str2[count1] = str1[i];
			count1++;
		}
		else if (isupper(str1[i]))
		{
			str3[count2] = str1[i];
			count2++;
		}
	}
	for (int i = 0; i < count1; i++)
	{
		if (str2[i] == 'r')
		{
			str4[0] = 'r';
		}
		else if (str2[i] == 'o')
		{
			str4[1] = 'o';
		}
		else if (str2[i] == 'y')
		{
			str4[2] = 'y';
		}
		else if (str2[i] == 'g')
		{
			str4[3] = 'g';
		}
		else if (str2[i] == 'b')
		{
			str4[4] = 'b';
		}
		else if (str2[i] == 'i')
		{
			str4[5] = 'i';
		}
		else if (str2[i] == 'v')
		{
			str4[6] = 'v';
		}
		if (strcmp(str4, "roygbiv") == 0)
		{
			break;
		}
	}
	for (int i = 0; i < count2; i++)
	{
		if (str3[i] == 'R')
		{
			str5[0] = 'R';
		}
		else if (str3[i] == 'O')
		{
			str5[1] = 'O';
		}
		else if (str3[i] == 'Y')
		{
			str5[2] = 'Y';
		}
		else if (str3[i] == 'G')
		{
			str5[3] = 'G';
		}
		else if (str3[i] == 'B')
		{
			str5[4] = 'B';
		}
		else if (str3[i] == 'I')
		{
			str5[5] = 'I';
		}
		else if (str3[i] == 'V')
		{
			str5[6] = 'V';
		}
		if (strcmp(str5, "ROYGBIV") == 0)
		{
			break;
		}
	}
	if (str4[0] == 'r' && str4[6] == 'v' && str4[1] == 'o' && str4[2] == 'y' && str4[3] == 'g' && str4[4] == 'b' && str4[5] == 'i' && str5[0] == 'R' && str5[6] == 'V' && str5[1] == 'O' && str5[2] == 'Y' && str5[3] == 'G' && str5[4] == 'B' && str5[5] == 'I')
	{
		printf("YeS");
	}
	if (str4[0] == 'r' && str4[6] == 'v' && str4[1] == 'o' && str4[2] == 'y' && str4[3] == 'g' && str4[4] == 'b' && str4[5] == 'i')
	{
		if (str5[0] != 'R' || str5[6] != 'V' || str5[1] != 'O' || str5[2] != 'Y' || str5[3] != 'G' || str5[4] != 'B' || str5[5] != 'I')
		{
			printf("yes");
		}

	}
	if (str5[0] == 'R' && str5[6] == 'V' && str5[1] == 'O' && str5[2] == 'Y' && str5[3] == 'G' && str5[4] == 'B' && str5[5] == 'I')
	{
		if (str4[0] != 'r' || str4[6] != 'v' || str4[1] != 'o' || str4[2] != 'y' || str4[3] != 'g' || str4[4] != 'b' || str4[5] != 'i')
		{
			printf("YES");
		}
		
	}
	if (str4[0] != 'r' || str4[6] != 'v' || str4[1] != 'o' || str4[2] != 'y' || str4[3] != 'g' || str4[4] != 'b' || str4[5] != 'i')
	{
		if (str5[0] != 'R' || str5[6] != 'V' || str5[1] != 'O' || str5[2] != 'Y' || str5[3] != 'G' || str5[4] != 'B' || str5[5] != 'I')
		{
			printf("NO!");
		}
	}
}