#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct info
{
	char name[15];
	int age;
	int weight;
}info;


int main(void)
{
	while (1)
	{
		info num1[1];
		scanf("%s %d %d", num1[0].name, &num1[0].age, &num1[0].weight);
		if (strcmp(num1[0].name, "#") == 0 && num1[0].age == 0 && num1[0].weight == 0)
		{
			break;
		}
		if (num1[0].age > 17 || num1[0].weight >= 80)
		{
			printf("%s Senior\n", num1[0].name);
		}
		else
		{
			printf("%s Junior\n", num1[0].name);
		}

	}
}