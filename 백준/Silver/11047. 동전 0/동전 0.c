#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
int search(int* ary, int size, int key)
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
	char num2[10];

	int ary1[10] = { 0, };
	int count = 0;

	scanf("%d %s", &num1, num2);
	int num3 = strlen(num2);
	int result = 0;
	int num4 = atoi(num2);
	int num5 = 0;
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary1[i]);
	}

	
	if (ary1[num1 - 1] >= num4 && num1 != 1)
	{
		for (int i = 0; i < num1; i++)
		{
			if (ary1[i] >= atoi(num2))
			{
				count = i;
				break;
			}
		}
		for (int i = count; i >= 0; i--)
		{
			if (num4 >= ary1[i])
			{
				result += num4 / ary1[i];
				num4 -= (num4 / ary1[i]) * ary1[i];
			}
		}
		printf("%d", result);
	}
	else if (ary1[num1 - 1] < num4 && num1 != 1)
	{
		for (int i = num1 - 1; i >= 0; i--)
		{
			if (num4 / ary1[i] >= 1)
			{
				result += num4 / ary1[i];
				num4 -= (num4 / ary1[i]) * ary1[i];
			}
		}
		printf("%d", result);
	}
	if (num1 == 1)
	{
		printf("%d", num4 / ary1[0]);
	}
}

	 