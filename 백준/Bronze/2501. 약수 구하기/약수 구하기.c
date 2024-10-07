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
	int num3 = 1;

	int count = 0;

	int ary1[100000] = { 0, };

	scanf("%d %d", &num1, &num2);

	while (num3 <= num1)
	{
		if (num1 % num3 == 0)
		{
			ary1[count] = num3;
			count++;
		}
		num3++;
		
	}
	printf("%d", ary1[num2 - 1]);

}