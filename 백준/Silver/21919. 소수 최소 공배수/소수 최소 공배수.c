#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

long long int ary1[10000] = { 0, };
long long int ary2[10000] = { 0, };

int compare(const void* num1, const void* num2) 
{
  long long int a = *(long long int*)num1;
  long long int b = *(long long int*)num2;
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
	scanf("%d", &num1);

	long long int result = 1;

	int index = 0;
	for (int i = 0; i < num1; i++)
	{
		scanf("%lld", &ary1[i]);
		int count = 2;
		int count1 = 0;
		
		if (ary1[i] == 2)
		{
			ary2[index] = ary1[i];
			index++;

		}
		else if (ary1[i] % 2 == 1)
		{
			while (count * count <= ary1[i])
			{
				if (ary1[i] % count == 0)
				{
					count1++;
					break;
				}
				count++;
			}
			if (count1 == 0)
			{
				ary2[index] = ary1[i];
				index++;
			}
		}
		
	}
	qsort(ary2, index, sizeof(long long int), compare);

	
	for (int i = 0; i < index; i++)
	{
		if (ary2[i] != ary2[i + 1])
		{
			result *= ary2[i];
		}
	}
	if (index != 0)
	{
		printf("%lld\n", result);
	}
	else
	{
		printf("-1\n");
	}

}