#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int ary[100000] = { 0, };
int ary1[100000] = { 0, };

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
	scanf("%d %d", &num1, &num2);

	int index1 = 0;
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary[i]);
		if (abs(ary[i] - num2) != 0)
		{
			ary1[index1] = abs(ary[i] - num2);
			index1++;
		}

	}
	if (index1 == 0)
	{
		printf("0\n");
	}
	else if (index1 == 1)
	{
		printf("%d\n", ary1[0]);
	}
	else
	{
		qsort(ary1, index1, sizeof(int), compare);
		int count2 = 0;

		for (int i = 0; i < index1; i++)
		{
			if (ary1[i] % ary1[0] != 0)
			{
				count2++;
				break;
			}
		}
		if (count2 == 0)
		{
			printf("%d\n", ary1[0]);
		}
		else
		{
			int count = (ary1[0] / 2);

			while (count >= 1)
			{
				int count1 = 0;
				for (int i = 0; i < index1; i++)
				{
					if (ary1[i] % count != 0)
					{
						count1++;
						break;
					}
				}

				if (count1 == 0)
				{
					printf("%d\n", count);
					break;
				}

				count--;
			}
		}
		
		
	}
	


}
