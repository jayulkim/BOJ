#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

int ary[10000][10] = {0,};

int ary2[10000] = { 0, };

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	int result = 0;
	for (int i = 0; i < num1; i++)
	{
		int ary1[10] = { 0, 0, 0 , 0, 0, 0, 0,};
		scanf("%d %d %d", &ary[i][0], &ary[i][1], &ary[i][2]);
		ary1[ary[i][0]]++;
		ary1[ary[i][1]]++;
		ary1[ary[i][2]]++;
		//printf("%d %d %d", ary1[ary[i][0]], ary1[ary[i][1]], ary1[ary[i][2]]);

		if (ary1[ary[i][0]] == 3 || ary1[ary[i][1]] == 3 || ary1[ary[i][2]] == 3)
		{
			for (int j = 0; j < 3; j++)
			{
				if (ary1[ary[i][j]] == 3)
				{
					ary2[i] = 10000 + ary[i][j] * 1000;
					//printf("%d\n", 10000 + ary[i][j] * 1000);
					break;
				}
			}
		}
		else if (ary1[ary[i][0]] == 2 || ary1[ary[i][1]] == 2 || ary1[ary[i][2]] == 2)
		{
			for (int j = 0; j < 3; j++)
			{
				if (ary1[ary[i][j]] == 2)
				{
					ary2[i] = 1000 + ary[i][j] * 100;
					//printf("%d\n", 1000 + ary[i][j] * 100);
					break;
				}
			}
		}
		else if (ary1[ary[i][0]] == 1 && ary1[ary[i][1]] == 1 && ary1[ary[i][2]] == 1)
		{
			int max = 0;
			for (int j = 0; j < 3; j++)
			{
				if (max <= ary[i][j])
				{
					max = ary[i][j];
				}
			}
			ary2[i] = max * 100;
			//printf("%d\n", max);
		}
		if (ary2[i] >= result)
		{
			result = ary2[i];
		}
	}
	printf("%d\n", result);
}