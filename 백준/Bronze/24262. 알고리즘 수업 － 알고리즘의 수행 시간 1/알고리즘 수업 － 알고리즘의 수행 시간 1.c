#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int binsearch(int data[], int n, int key) {
    int low, high;
    int mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (key == data[mid]) {            //탐색 성공
            return mid;
        }
        else if (key < data[mid]) {        //탐색 범위를 아래쪽으로
            high = mid - 1;
        }
        else if (key > data[mid]) {        //탐색 범위를 위쪽으로
            low = mid + 1;
        }
    }
    return -1;                            //탐색 실패
}

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
    
    scanf("%d", &num1);
    printf("1\n0");
   
   
}