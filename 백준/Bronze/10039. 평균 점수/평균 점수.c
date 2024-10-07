#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>


int main(void)
{
    int ary[5] = { 0, };
    int result = 0;

    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &ary[i]);
        if (ary[i] < 40)
        {
            ary[i] = 40;
        }
       
    }
    for (int i = 0; i < 5; i++)
    {
        result += ary[i];


    }
  
   
    printf("%d", result / 5);


    
  
   
}