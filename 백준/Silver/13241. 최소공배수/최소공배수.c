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
	long long int num1 = 0;
	long long int num2 = 0;

	long long int num3 = 0;

	long long int result = 0;
	long long int count1 = 0;

	
	scanf("%lld %lld", &num1, &num2);

	if (num1 >= num2)
	{
		if (num1 % num2 == 0)
		{
			printf("%lld", num1);

		}
		else if (num1 % num2 != 0)
		{
			for (int i = 1; i <= num1 % num2; i++)
			{
				if (num1 % i == 0 && num2 % i == 0)
				{
					count1 = i;
				}
			}
			printf("%lld", num1 * num2 / count1);
		}
	}
	else if (num1 < num2)
	{
		if (num2 % num1 == 0)
		{
			printf("%lld", num2);

		}
		else if (num2 % num1 != 0)
		{
			for (int i = 1; i <= num2 % num1; i++)
			{
				if (num1 % i == 0 && num2 % i == 0)
				{
					count1 = i;
				}
			}
			printf("%lld", num1 * num2 / count1);
		}
	}


}
	 
