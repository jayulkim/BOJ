#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct info
{
	char str[60];
	int sum;
	int len;
}info;

info list[60];

int compare(const void* num1, const void* num2) 
{
  info* a = (info*)num1;
  info* b = (info*)num2;
  if (a -> len> b ->len)
  {
	  return 1;
  }
  else if (a ->len < b->len)
  {
	  return -1;
  }
  else
  {
	  if (a->sum > b->sum)
	  {
		  return 1;
	  }
	  else if (a->sum < b->sum)
	  {
		  return -1;
	  }
	  else
	  {
		  return strcmp(a->str, b->str);
	  }
  }

}


int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		scanf("%s", list[i].str);
		int num2 = strlen(list[i].str);
		list[i].len = num2;
		int sum1 = 0;
		for (int j = 0; j < num2; j++)
		{
			if (list[i].str[j] == '1')
			{
				sum1 += 1;
			}
			else if (list[i].str[j] == '2')
			{
				sum1 += 2;
			}
			else if (list[i].str[j] == '3')
			{
				sum1 += 3;
			}
			else if (list[i].str[j] == '4')
			{
				sum1 += 4;
			}
			else if (list[i].str[j] == '5')
			{
				sum1 += 5;
			}
			else if (list[i].str[j] == '6')
			{
				sum1 += 6;
			}
			else if (list[i].str[j] == '7')
			{
				sum1 += 7;
			}
			else if (list[i].str[j] == '8')
			{
				sum1 += 8;
			}
			else if (list[i].str[j] == '9')
			{
				sum1 += 9;
			}
		}
		list[i].sum = sum1;
	}
	qsort(list, num1, sizeof(info), compare);
	for (int i = 0; i < num1; i++)
	{
		printf("%s\n", list[i].str);
	}

}