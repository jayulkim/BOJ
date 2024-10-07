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
	while (1)
	{
		int num1 = 0;
		int count = 0;
		int num3 = 1;

		int num2 = 0;
		int ary1[100000] = { 0, };

		scanf("%d", &num1);
		if (num1 == -1)
		{
			break;
		}
		while (num3 < num1)
		{
			if (num1 % num3 == 0)
			{
				ary1[count] = num3;
				count++;
			}
			num3++;

		}
		for (int i = 0; i < count; i++)
		{
			num2 += ary1[i];
		}

		if (num2 == num1)
		{
			printf("%d = %d", num1, ary1[0]);
			for (int i = 1; i < count; i++)
			{
				printf(" + %d", ary1[i]);
			}
			printf("\n");
		}
		else
		{
			printf("%d is NOT perfect.\n", num1);
		}
	}
	



}