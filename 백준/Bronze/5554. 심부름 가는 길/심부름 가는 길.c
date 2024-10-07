#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <math.h>

#include <stdlib.h>

int main(void)

{

    int num1= 0;

    int num2 = 0;

    int num3 = 0;

    int num4 = 0;

    

    int result = 0;

    scanf("%d", &num1);

    scanf("%d", &num2);

    scanf("%d", &num3);

    scanf("%d", &num4);

    

    result = result + num1 +num2 + num3 + num4;

    printf("%d\n%d", result / 60, result % 60);

}    