#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
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
	while (1)
	{
		int num1 = 0;
		int num2 = 0;
		int num3 = 0;
		int ary1[3] = { 0, };


		scanf("%d %d %d", &num1, &num2, &num3);
		if (num1 == 0 && num2 == 0 && num3 == 0)
		{
			break;
		}
		ary1[0] = num1;
		ary1[1] = num2;
		ary1[2] = num3;
		qsort(ary1, 3, sizeof(int), compare);

		if (ary1[0] + ary1[1] <= ary1[2])
		{
			printf("Invalid\n");
		}
		else if (ary1[0] == ary1[1] && ary1[1] == ary1[2])
		{
			printf("Equilateral\n");
		}
		else if (ary1[1] == ary1[2] && ary1[1] != ary1[0])
		{
			printf("Isosceles\n");
		}
		else if (ary1[0] == ary1[1] && ary1[1] != ary1[2])
		{
			printf("Isosceles\n");
		}

		else if (ary1[0] != ary1[1] && ary1[1] != ary1[2] && ary1[0] != ary1[2])
		{
			printf("Scalene\n");
		}

	}
	


	
}