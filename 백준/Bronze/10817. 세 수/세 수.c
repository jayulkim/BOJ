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
int main(void)
{
    int ary1[3] = { 0, };

    scanf("%d %d %d", &ary1[0], &ary1[1], &ary1[2]);
   
    qsort(ary1, 3, sizeof(int), compare);

    printf("%d\n", ary1[1]);
   
   

}
