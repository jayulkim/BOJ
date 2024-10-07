#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

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
	char str1[1000000];
	
	int ary1[30] = { 0, };
	int num1 = 0;
	int num2 = 0;
	int count = 0;
	char str2[30] = { 'A', 'B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

	gets(str1);
	int num3 = strlen(str1);
	for (int i = 0; i < num3; i++)
	{
		if (str1[i] == 'A' || str1[i] == 'a')
		{
			ary1[0] += 1;
		}
		if (str1[i] == 'B' || str1[i] == 'b')
		{
			ary1[1] += 1;
		}
		if (str1[i] == 'C' || str1[i] == 'c')
		{
			ary1[2] += 1;
		}
		if (str1[i] == 'D' || str1[i] == 'd')
		{
			ary1[3] += 1;
		}
		if (str1[i] == 'E' || str1[i] == 'e')
		{
			ary1[4] += 1;
		}
		if (str1[i] == 'F' || str1[i] == 'f')
		{
			ary1[5] += 1;
		}
		if (str1[i] == 'G' || str1[i] == 'g')
		{
			ary1[6] += 1;
		}
		if (str1[i] == 'H' || str1[i] == 'h')
		{
			ary1[7] += 1;
		}
		if (str1[i] == 'I' || str1[i] == 'i')
		{
			ary1[8] += 1;
		}
		if (str1[i] == 'J' || str1[i] == 'j')
		{
			ary1[9] += 1;
		}
		if (str1[i] == 'K' || str1[i] == 'k')
		{
			ary1[10] += 1;
		}
		if (str1[i] == 'L' || str1[i] == 'l')
		{
			ary1[11] += 1;
		}
		if (str1[i] == 'M' || str1[i] == 'm')
		{
			ary1[12] += 1;
		}
		if (str1[i] == 'N' || str1[i] == 'n')
		{
			ary1[13] += 1;
		}
		if (str1[i] == 'O' || str1[i] == 'o')
		{
			ary1[14] += 1;
		}
		if (str1[i] == 'P' || str1[i] == 'p')
		{
			ary1[15] += 1;
		}
		if (str1[i] == 'Q' || str1[i] == 'q')
		{
			ary1[16] += 1;
		}
		if (str1[i] == 'R' || str1[i] == 'r')
		{
			ary1[17] += 1;
		}
		if (str1[i] == 'S' || str1[i] == 's')
		{
			ary1[18] += 1;
		}
		if (str1[i] == 'T' || str1[i] == 't')
		{
			ary1[19] += 1;
		}
		if (str1[i] == 'U' || str1[i] == 'u')
		{
			ary1[20] += 1;
		}
		if (str1[i] == 'V' || str1[i] == 'v')
		{
			ary1[21] += 1;
		}
		if (str1[i] == 'W' || str1[i] == 'w')
		{
			ary1[22] += 1;
		}
		if (str1[i] == 'X' || str1[i] == 'x')
		{
			ary1[23] += 1;
		}
		if (str1[i] == 'Y' || str1[i] == 'y')
		{
			ary1[24] += 1;
		}
		if (str1[i] == 'Z' || str1[i] == 'z')
		{
			ary1[25] += 1;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (ary1[i] > num1)
		{
			num1 = ary1[i];
			num2 = i;

		}
		
	}
	qsort(ary1, 26, sizeof(int), compare);


	if (ary1[24] == ary1[25] && ary1[24] != 0 && ary1[25] != 0)
	{
		count += 1;
	}

	if (count != 0)
	{
		printf("?");
	}
	if (count == 0)
	{
		printf("%c", str2[num2]);
	}
}