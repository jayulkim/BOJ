#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int ary1[3000][3000] = { 0, };
int ary2[3000] = { 0, };
int sum[3000] = { 0, };
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

		for (int j = 0; j < num2; j++)
		{
			scanf("%d", &ary1[i][j]);
		}

	}
	for (int i = 0; i < num2; i++)
	{
		
		for (int j = 0; j < num1; j++)
		{
			ary2[i] += ary1[j][i];

		}
	}
	int num3 = 0;

	scanf("%d", &num3);

	int result = 0;

	
	for (int i = 0; i < num3; i++)
	{
		sum[0] += ary2[i];
	}
	for (int i = 0; i < num2 - num3; i++)
	{
		sum[i + 1] = sum[i] + ary2[i+num3] - ary2[i];
	}

	qsort(sum, num2 - num3 +1, sizeof(int), compare);
	printf("%d\n", sum[num2 - num3]);

}
