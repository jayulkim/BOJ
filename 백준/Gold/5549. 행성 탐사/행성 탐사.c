#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

typedef struct ground
{
	char name[1];
	int ice;
	int jungle;
	int sea;
}ground;

ground list[1002][1002];
ground listsum[1002][1002];

int main(void)
{
	int num1 = 0;
	int num2 = 0;

	int num3 = 0;
	scanf("%d %d", &num1, &num2);

	scanf("%d", &num3);
	getchar();
	for (int i = 1; i <= num1; i++)
	{
		for (int j = 1; j <= num2 + 1; j++)
		{
			scanf("%c", &list[i][j].name[0]);
			if (list[i][j].name[0] == 'J')
			{
				list[i][j].jungle++;
				
				//printf("%d\n", listsum[i][j].jungle);
			}
			else if (list[i][j].name[0] == 'I')
			{
				list[i][j].ice++;
				
				//printf("%d\n", listsum[i][j].ice);
			}
			else if (list[i][j].name[0] == 'O')
			{
				list[i][j].sea++;
				
			}
			listsum[i][j].jungle = list[i][j].jungle + listsum[i - 1][j].jungle + listsum[i][j - 1].jungle - listsum[i - 1][j - 1].jungle;
			listsum[i][j].ice = list[i][j].ice + listsum[i - 1][j].ice + listsum[i][j - 1].ice - listsum[i - 1][j - 1].ice;
			listsum[i][j].sea = list[i][j].sea + listsum[i - 1][j].sea + listsum[i][j - 1].sea - listsum[i - 1][j - 1].sea;

		}
//		printf("\n");
	}

	for (int i = 0; i < num3; i++)
	{
		int x1 = 0;
		int y1 = 0;
		int x2 = 0;
		int y2 = 0;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		printf("%d %d %d\n", listsum[x2][y2].jungle - listsum[x1 - 1][y2].jungle - listsum[x2][y1 - 1].jungle + listsum[x1 - 1][y1 - 1].jungle, listsum[x2][y2].sea - listsum[x1 - 1][y2].sea - listsum[x2][y1 - 1].sea + listsum[x1 - 1][y1 - 1].sea, listsum[x2][y2].ice - listsum[x1 - 1][y2].ice - listsum[x2][y1 - 1].ice + listsum[x1 - 1][y1 - 1].ice);
	}

}
