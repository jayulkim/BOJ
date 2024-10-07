#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

char map[52][52];

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

	for (int i = 0; i < num1; i++)
	{
		scanf("%s", map[i]);
	}
	
	int index = 0;
	int index1 = 0;

	for (int k = 0; k + 8 <= num1; k++)
	{
		for (int n = 0; n + 8 <= num2; n++)
		{
			for (int i = k; i < 8 + k; i += 2)
			{
				for (int j = n; j < 8 + n; j += 2)
				{
					if (map[i][j] != 'B')
					{
						ary[index]++;
					}
					if (map[i][j + 1] != 'W')
					{
						ary[index]++;
					}
					if (map[i + 1][j] != 'W')
					{
						ary[index]++;
					}
					if (map[i + 1][j + 1] != 'B')
					{
						ary[index]++;
					}

				}

			}
			for (int i = k; i < 8 + k; i += 2)
			{
				for (int j = n; j < 8 + n; j += 2)
				{
					if (map[i][j] != 'W')
					{
						ary1[index1]++;
					}
					if (map[i][j + 1] != 'B')
					{
						ary1[index1]++;
					}
					if (map[i + 1][j] != 'B')
					{
						ary1[index1]++;
					}
					if (map[i + 1][j + 1] != 'W')
					{
						ary1[index1]++;
					}

				}

			}
			index++;
			index1++;
		}
	}
	

	qsort(ary, index, sizeof(int), compare);
	qsort(ary1, index1, sizeof(int), compare);

	if (ary[0] < ary1[0])
	{
		printf("%d\n", ary[0]);
	}
	else if (ary[0] >= ary1[0])
	{
		printf("%d\n", ary1[0]);
	}


}