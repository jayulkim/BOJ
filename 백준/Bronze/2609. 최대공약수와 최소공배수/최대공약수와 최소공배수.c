#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
int lower_bound(int* ary, int size, int key)
{
	int start = 0, end = size - 1;
	while (start < end)
	{
		int cen = (start + end) / 2;
		if (ary[cen] >= key)
		{
			end = cen;
		}
		else
		{
			start = cen + 1;
		}
	}
	return end;
}
int upper_bound(int* ary, int size, int key)
{
	int start = 0, end = size - 1;
	while (start < end)
	{
		int cen = (start + end) / 2;
		if (ary[cen] > key)
		{
			end = cen;
		}
		else
		{
			start = cen + 1;
		}
	}
	return end;
}

int main(void)
{
	int num1 = 0;
	int num2 = 0;

	int num3 = 0;

	int result = 0;
	int count = 0;

	scanf("%d %d", &num1, &num2);

	for (int i = num1; i >= 1; i--)
	{
		if (num1 % i == 0)
		{
			result = i;
		}
		for (int j = num2; j >= 1; j--)
		{
			if (num2 % j == 0)
			{
				count = j;
			}
			if (result == count)
			{
				num3 = result;
				break;
			}
		}
		if (result == count)
		{
			break;
		}
	}
	printf("%d\n%d", num3, num2 * num1 / num3);
}
	
