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
	ary1[0] = 0;
	ary1[1] = 1;

	int result = 0;

	scanf("%d", &num1);

	for (int i = 0; i < num1 - 1; i++)
	{
		result = ary1[i] + ary1[i + 1];

		ary1[i + 2] = result;
		
	}

	printf("%d", ary1[num1]);

}
	
