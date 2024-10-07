#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <math.h>

#include <stdlib.h>

#include <string.h>

#include <ctype.h>

int main(void)

{

 

   

   char num1[50];

  

   gets(num1);

   

   for (int i = 0; i < atoi(num1); i++)

   {

   

       char str1[20];

       

       gets(str1);

       

       int count = 0;

       int num2 = strlen(str1);

       for (int j = 0; j < num2; j++)

       {

           if (isupper(str1[j]))

           {

               str1[j] = tolower(str1[j]);

           }

           

       }

       for (int j = 0; j < num2 / 2; j++)

       {

           if (str1[j] != str1[num2 - 1 - j])

           {

               count++;

               break;

           }

           

       }

       

       if (count == 0)

       {

           printf("Yes\n");

           

       }

       else

       {

           printf("No\n");

       }

       

   }

   

}