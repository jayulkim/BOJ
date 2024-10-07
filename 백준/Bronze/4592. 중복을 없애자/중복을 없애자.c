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
	while (1)
	{
		int num1 = 0;
		scanf("%d", &num1);

		if (num1 == 0)
		{
			break;
		}

		int ary1[50] = { 0, };
		int ary2[50] = { 0, };


		for (int i = 0; i < num1; i++)
		{
			scanf("%d", &ary1[i]);
	
		}
		int num2 = 0;
		int num3 = 0;
		if (num1 > 1)
		{
			for (int j = 0; j <= num1 - 1; j++)
			{
				if (ary1[j] == ary1[j + 1])
				{
					num2++;

				}
				if (num2 == 0)
				{
					printf("%d ", ary1[j]);
				}
				num2 = 0;
			}

		}
	
		else if (num1 == 1)
		{
			printf("%d ", ary1[0]);
		}
		
		
	
		printf("$");
		printf("\n");

	}
	

}