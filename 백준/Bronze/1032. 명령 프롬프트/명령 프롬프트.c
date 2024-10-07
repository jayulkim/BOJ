#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
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


	char str1[51][51];

	char str2[51][51];

	int num1 = 0;
	int count = 0;
	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		scanf("%s", str1[i]);


	}
	for (int k = 0; k < strlen(str1[0]); k++)
	{
		for (int j = 0; j < num1; j++)
		{

			if (str1[0][k] == str1[j][k])
			{
				str2[0][k] = str1[j][k];

			}
			
			else
			{

				str2[0][k] = '?';
				break;
			}


		}
	}
		
		
	for (int i = 0; i < strlen(str1); i++)
	{
		printf("%c", str2[0][i]);
	}
	

	
	
	
}
	