#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int ary[10] = { 0, };

	for (int i = 0; i < 8; i++)
	{
		scanf("%d", &ary[i]);
	}
	if (ary[0] == 1 && ary[1] == 2 && ary[2] == 3 && ary[3] == 4 && ary[4] == 5 && ary[5] == 6 && ary[6] == 7 && ary[7] == 8)
	{
		printf("ascending");
	}
	else if (ary[0] == 8 && ary[1] == 7 && ary[2] == 6 && ary[3] == 5 && ary[4] == 4 && ary[5] == 3 && ary[6] == 2 && ary[7] == 1)
	{
		printf("descending");
	}
	else
	{
		printf("mixed");
	}
}