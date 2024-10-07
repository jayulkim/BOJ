#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);
	int* ary1 = (int*)malloc(sizeof(int) * (num1 + 1));
	int ary2[100000] = { 0, };

	int start = 0;
	int end = 0;

	for (int i = 1; i < num1 + 1; i++)
	{
		scanf("%d", &ary1[i]);
		ary2[i] = ary2[i - 1] + ary1[i];
	}
	for (int i = 0; i < num2; i++)
	{
		scanf("%d %d", &start, &end);

		if (start != end)
		{
			printf("%d\n", ary2[end] - ary2[start - 1]);
		}
		else if (start == end)
		{
			printf("%d\n", ary1[end]);
		}
	}
	free(ary1);

}