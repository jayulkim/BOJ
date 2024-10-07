#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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
	char num1[100000];

	scanf("%s", &num1);

	int ary1[100000] = { 0, };
	int num2 = strlen(num1);
	int result = 0;
	for (int i = 0; i < num2; i++)
	{
		ary1[i] = num1[i] - 48;
	}
	qsort(ary1, num2, sizeof(int), compare);

	if (ary1[0] != 0)
	{
		printf("%d", -1);
	}
	else if (ary1[0] == 0)
	{
		for (int i = 0; i < num2; i++)
		{
			result += ary1[i] % 3;
		}
		if (result % 3 == 0)
		{
			for (int i = num2 - 1; i >= 0; i--)
			{
				printf("%d", ary1[i]);
			}
		}
		else
		{
			printf("%d", -1);
		}
	}
}