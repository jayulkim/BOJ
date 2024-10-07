#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ary1[1050][1050] = { 0, };
int ary2[1050][1050] = { 0, };

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);

	

	for (int i = 1; i < num1 + 1; i++)
	{
		for (int j = 1; j < num1 + 1; j++)
		{
			scanf("%d", &ary1[i][j]);
			
		}
	}
	for (int i = 1; i < num1 + 1; i++)
	{
		for (int j = 1; j < num1 + 1; j++)
		{
			ary2[i][j] = ary2[i][j - 1] + ary2[i - 1][j] - ary2[i - 1][j - 1] + ary1[i][j];
			
		}
	}


	int x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;
	for (int j = 0; j < num2; j++)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", ary2[x2][y2] + ary2[x1 - 1][y1 - 1] - ary2[x2][y1 - 1] - ary2[x1 - 1][y2]);

	}

}