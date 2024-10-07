#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>


int main(void)
{
    int num1 = 0;

    scanf("%d", &num1);

    if ((num1 - 1) % 8 == 0)
    {
        printf("1");
    }
    if ((num1 - 2) % 8 == 0 || (num1 - 8) % 8 == 0)
    {
        printf("2");
    }
    if ((num1 - 3) % 8 == 0 || (num1 - 7) % 8 == 0)
    {
        printf("3");
    }
    if ((num1 - 4) % 8 == 0 || (num1 - 6) % 8 == 0)
    {
        printf("4");
    }
    if ((num1 - 5) % 8 == 0)
    {
        printf("5");
    }
  
   
}