#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

int dp0[1001][3];

int dp1[1001][3];

int dp2[1001][3];

int ary[1001][3];

int min(int num1, int num2)

{

    if (num1 < num2)

    {

        return num1;

    }

    else

    {

        return num2;

    }

}

int main(void)

{

    int n = 0;

    scanf("%d", &n);

    for(int j = 0; j < n; j++)

    {

        scanf("%d %d %d", &ary[j][0], &ary[j][1], &ary[j][2]);

    }

    dp0[0][0] = ary[0][0];

    dp0[0][1] = ary[0][1];

    dp0[0][2] = ary[0][2];

    dp1[0][0] = ary[0][0];

    dp1[0][1] = ary[0][1];

    dp1[0][2] = ary[0][2];

    dp2[0][0] = ary[0][0];

    dp2[0][1] = ary[0][1];

    dp2[0][2] = ary[0][2];

    dp0[1][1] = dp0[0][0] + ary[1][1];

    dp0[1][2] = dp0[0][0] + ary[1][2];

    dp0[2][0] = min(dp0[1][1], dp0[1][2]) + ary[2][0];

    dp0[2][1] = dp0[1][2] + ary[2][1];

    dp0[2][2] = dp0[1][1] + ary[2][2];

    dp1[1][0] = dp1[0][1] + ary[1][0];

    dp1[1][2] = dp1[0][1] + ary[1][2];

    dp1[2][1] = min(dp1[1][0], dp1[1][2]) + ary[2][1];

    dp1[2][0] = dp1[1][2] + ary[2][0];

    dp1[2][2] = dp1[1][0] + ary[2][2];

    dp2[1][0] = dp2[0][2] + ary[1][0];

    dp2[1][1] = dp2[0][2] + ary[1][1];

    dp2[2][2] = min(dp2[1][0], dp2[1][1]) + ary[2][2];

    dp2[2][0] = dp2[1][1] + ary[2][0];

    dp2[2][1] = dp2[1][0] + ary[2][1];

    for(int j = 3; j < n; j++)

    {

        dp0[j][0] = min(dp0[j - 1][1], dp0[j - 1][2]) + ary[j][0];

        dp0[j][1] = min(dp0[j - 1][0], dp0[j - 1][2]) + ary[j][1];

        dp0[j][2] = min(dp0[j - 1][1], dp0[j - 1][0]) + ary[j][2];

        dp1[j][0] = min(dp1[j - 1][1], dp1[j - 1][2]) + ary[j][0];

        dp1[j][1] = min(dp1[j - 1][0], dp1[j - 1][2]) + ary[j][1];

        dp1[j][2] = min(dp1[j - 1][1], dp1[j - 1][0]) + ary[j][2];

        dp2[j][0] = min(dp2[j - 1][1], dp2[j - 1][2]) + ary[j][0];

        dp2[j][1] = min(dp2[j - 1][0], dp2[j - 1][2]) + ary[j][1];

        dp2[j][2] = min(dp2[j - 1][1], dp2[j - 1][0]) + ary[j][2];

    }

    printf("%d", min(min(min(dp0[n - 1][1], dp0[n - 1][2]), min(dp1[n - 1][0], dp1[n - 1][2])), min(dp2[n - 1][0], dp2[n - 1][1])));

}