#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int dp0[45] = { 0, };
int dp1[45] = { 0, };

int main(void)
{
    dp0[0] = 1;
    dp0[1] = 0;
    dp1[0] = 0;
    dp1[1] = 1;
    for (int i = 2; i <= 40; i++)
    {
        dp0[i] = dp0[i - 1] + dp0[i - 2];
        dp1[i] = dp1[i - 1] + dp1[i - 2];
    }
    int num1 = 0;
    scanf("%d", &num1);
    for (int i = 0; i < num1; i++)
    {
        int num2 = 0;
        scanf("%d", &num2);
        printf("%d %d\n", dp0[num2], dp1[num2]);
    }
}