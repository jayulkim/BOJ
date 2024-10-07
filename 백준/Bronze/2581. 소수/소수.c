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
	int num1 = 0;
	int num2 = 0;




	int ary1[10000] = { 0, };

	int result = 0;

	scanf("%d", &num1);
	scanf("%d", &num2);

	for (int i = num2; i >= num1; i--)
	{
		int num3 = 2;
		int count1 = 0;
		int count2 = 0;
		int count3 = 0;
		while (num3 <= i / 2)
		{
			if (i % num3 == 0)
			{
				count1++;
			}
			num3++;
		}
		if (count1 == 0)
		{
			
			ary1[count2] = i;
			count2++;
		}
		
		for (int j = 0; j < count2; j++)
		{
			result += ary1[j];

		}
		
	}
	if (ary1[0] != 0)
	{
		if (num2 != 1 && num1 == 1)
		{
			printf("%d\n%d", result - 1, ary1[0]+ 1);
		}
		if (num2 != 1 && num1 != 1)
		{
			printf("%d\n%d", result, ary1[0]);
		}
	}
	else
	{
		printf("-1");
	}

	if (num1 == 1 && num2 == 1)
	{
		printf("-1");
	}
	

}