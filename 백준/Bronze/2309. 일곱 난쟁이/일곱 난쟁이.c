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
	
	int ary1[30] = {0,};
	int result = 0;
	int count = 0;

	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &ary1[i]);
		result += ary1[i];
	}
	result -= 100;

	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9;j++)
		{
			count = ary1[i] + ary1[j];
			if (count == result)
			{
				ary1[i] = 0;
				ary1[j] = 0;
				break;
			}
		}
		if (count == result)
		{
			break;
		}
	}
	qsort(ary1, 9, sizeof(int), compare);

	for (int i = 0; i < 7; i++)
	{
		printf("%d\n", ary1[i + 2]);
	}


}
	
