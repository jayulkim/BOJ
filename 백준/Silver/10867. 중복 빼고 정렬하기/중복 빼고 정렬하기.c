#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ary1[100000];
int ary2[100000];

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
	int num1 = 0;

	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary1[i]);
	}

	qsort(ary1, num1, sizeof(int), compare);


	for (int i = 0; i < num1; i++)
	{
		int index = 0;
		if (ary1[i] != ary1[i + 1])
		{
			ary2[index] = ary1[i];
			printf("%d ", ary2[index]);
			index++;
		}
	}




}