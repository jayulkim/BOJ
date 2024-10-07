#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
int compare(const void* num1, const void* num2)
{
	char *a = *(char*)num1;
	char *b = *(char*)num2;
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
	char key[11];
	char password1[101];
	char password[11][11];

	scanf("%s", key);
	scanf("%s", password1);

	
	char key1[11];

	strcpy(key1, key);

	int num1 = strlen(key);
	int num2 = strlen(password1);
	qsort(key, num1, sizeof(char), compare);
	
	int num3 = 0;
	for (int i = 0; i < num1; i++)
	{
		int index = 1;
		password[i][0] = key[i];
		for (int j = (num2 / num1) * i; j < (num2 / num1) * i + (num2 / num1) ; j++)
		{
			password[i][index] = password1[j];
			index++;
		}
		num3 = index;
	}

	for (int i = 0; i < num1; i++)
	{
		for (int j = 0; j < num3; j++)
		{
			//printf("%c", password[i][j]);
		}
		//printf("\n");
	}

	int ary[11] = { 0, };
	for (int i = 0; i < num1; i++)
	{
		for (int j = 0; j < num1; j++)
		{
			if (password[j][0] == key1[i])
			{
				ary[i] = j;
				//printf("%d\n", j);
				
				password[j][0] = NULL;
				key1[i] = NULL;
				j = 0;
				break;
			}
		}
	
	}
	for (int j = 1; j < num3; j++)
	{
		for (int i = 0; i < num1; i++)
		{
			printf("%c", password[ary[i]][j]);
		}
	}

}
