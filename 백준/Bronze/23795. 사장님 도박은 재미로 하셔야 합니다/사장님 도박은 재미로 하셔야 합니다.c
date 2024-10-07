#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <math.h>

#include <stdlib.h>

int main(void)

{

    long long int num1= 0;

    

    long long int result = 0;

    

    while (1)

    {

        scanf("%lld", &num1);

        

        if (num1 == -1)

        {

            break;

        }

        

        result += num1;

    }

    printf("%lld", result);

}

    