#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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
    int x = 0;
    int y = 0;
    int w = 0;
    int h = 0;
    int* ary = (int*)malloc(sizeof(int) * 5);

    scanf("%d %d %d %d", &x, &y, &w, &h);

    ary[0] = sqrt((x - w) * (x - w) + (y - h) * (y - h));
    ary[1] = abs(x - w);
    ary[2] = abs(y - h);
    ary[3] = abs(y);
    ary[4] = abs(x);
    qsort(ary, 5, sizeof(int), compare);
    if (x == w || y == h)
    {
        printf("%d", 0);
    }
    else
    {
        printf("%d", ary[0]);
    }
   
}