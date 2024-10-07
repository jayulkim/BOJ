#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

int main(void)

{

    int num1 = 0;

    int num2 = 0;

    int num3 = 0;

    int num4 = 0;

    scanf("%d %d", &num1, &num2);

    scanf("%d %d", &num3, &num4);

    int num5 = num4 * num2;

    int num6 = num1 * num4 + num2 * num3;

    

    

    int result1 = num5;

    int result2 = num6;

    

    int num7 = num1 + num3;

    int num8 = num2;

    

    int result3 = num7;

    int result4 = num8;

    

    if (num2 != num4)

    {

        if (num5 > num6)

        {

            while (result2 >= 1)

            {

                if (num5 % result2 == 0 && num6 % result2 == 0)

                {

                    break;

                }

                result2--;

            }    

            printf("%d %d\n", num6 / result2, num5 / result2);

        }

        else if (num5 < num6)

        {

            while (result1 >= 1)

            {

                if (num5 % result1 == 0 && num6 % result1 == 0)

                {

                    break;

                }

                result1--;

            }

            printf("%d %d\n", num6 / result1, num5 / result1);

        }

        else

        {

            printf("1 1\n");

        }

    }

    else if (num2 == num4)

    {

        if (num8 > num7)

        {

            while(result3 >= 1)

            {

                if (num8 % result3 == 0 && num7 % result3 == 0)

                {

                    break;

                }

                result3--;

            }

            printf("%d %d\n", num7 / result3, num8 / result3);

        }

        else if (num8 < num7)

        {

            while (result4 >= 1)

            {

                if (num8 % result4 == 0 && num7 % result4 == 0)

                {

                    break;

                }

                result4--;

            }

            printf("%d %d\n", num7 / result4, num8 / result4);

        }

        else

        {

            printf("1 1\n");

        }

    }

        

}