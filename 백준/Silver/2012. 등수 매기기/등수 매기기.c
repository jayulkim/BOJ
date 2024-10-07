#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long int ary[500000] = {0,};

int compare(const void* num1, const void* num2) 
{
  long long int a = *(int*)num1;
  long long int b = *(int*)num2;
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
	scanf("%lld", &num1);

    for (int i = 0; i < num1; i++)
    {
        scanf("%d", &ary[i]);
    }

    qsort(ary, num1, sizeof(long long int), compare);
    
    int count = 1;
    long long int result = 0;
    for (int i = 0; i < num1; i++)
    {
        result += abs(ary[i] - count);
        count++;
    }
    printf("%lld\n", result);

}
