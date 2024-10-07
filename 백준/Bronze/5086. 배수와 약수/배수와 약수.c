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


		scanf("%d %d", &num1, &num2);

		if (num1 == 0 && num2 == 0)
		{
			break;
		}
		if (num2 % num1 == 0)
		{
			printf("factor\n");
		}
		else if (num1 % num2 == 0)
		{
			printf("multiple\n");
		}
		else
		{
			printf("neither\n");
		}
		

	}
	
	

}