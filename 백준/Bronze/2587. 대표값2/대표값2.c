#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
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
    int num = 5;
    int result = 0;

    int* ary = (int*)malloc(sizeof(int) * num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &ary[i]);
    }
    qsort(ary, num, sizeof(int), compare);
    
    for (int i = 0; i < num; i++)
    {
        result += ary[i];
    }

    printf("%d\n", result / num);
    printf("%d\n", ary[2]);
   
}