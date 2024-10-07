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
	long long int num1 = 0;

	char str1[100];

	scanf("%s %lld", str1, &num1);
	int num2 = strlen(str1);
	int result = 0;
	long long int num3 = 0;
	long long int num4 = atoi(str1);

	if (num1 < 10)
	{
		for (int i = num2 - 1; i >= 0; i--)
		{
			num3 = (str1[i] - 48);
			for (int j = 0; j < num2 - i - 1; j++)
			{
				
				num3 *= num1;

			}
			result += num3;

		}
		printf("%d", result);
	}
	else if (num1 == 10)
	{
		printf("%lld", num4);
	}
	else if (num1 > 10)
	{
		for (int i = num2 - 1; i >= 0; i--)
		{
			if (str1[i] - 55 >= 10)
			{
				num3 = (str1[i] - 55);
				for (int j = 0; j < num2 - i - 1; j++)
				{
					num3 *= num1;
				}
				result += num3;
			}
			else if (str1[i] - 55 < 10)
			{
				num3 = (str1[i] - 48);
				for (int j = 0; j < num2 - i - 1; j++)
				{

					num3 *= num1;

				}
				result += num3;
			}
			

		}
		printf("%d", result);
	}
	

}