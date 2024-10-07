#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int ary[30][200005] = {0,};
char str[200005];
int sum[30][200005] = {0,};

int main(void)
{
	scanf("%s", str);
	int num1 = 0;
	scanf("%d", &num1);

	int num2 = strlen(str);

	if (str[0] == 'a')
	{
		ary[0][0]++;	
	}
	sum[0][0] = ary[0][0];
	for (int i = 1; i < num2; i++)
	{
		if (str[i] == 'a')
		{
			ary[0][i]++;
		}
		sum[0][i] = ary[0][i] + sum[0][i-1];
	}
	if (str[0] == 'b')
	{
		ary[1][0]++;
	}
	sum[1][0] = ary[1][0];
	for (int i = 1; i < num2; i++)
	{
		if (str[i] == 'b')
		{
			ary[1][i]++;
		}
		sum[1][i] = ary[1][i] + sum[1][i - 1];
	}
	if (str[0] == 'c')
	{
		ary[2][0]++;
	}
	sum[2][0] = ary[2][0];
	for (int i = 1; i < num2; i++)
	{
		if (str[i] == 'c')
		{
			ary[2][i]++;
		}
		sum[2][i] = ary[2][i] + sum[2][i - 1];
	}
	if (str[0] == 'd')
	{
		ary[3][0]++;
	}
	sum[3][0] = ary[3][0];
	for (int i = 1; i < num2; i++)
	{
		if (str[i] == 'd')
		{
			ary[3][i]++;
		}
		sum[3][i] = ary[3][i] + sum[3][i - 1];
	}

	if (str[0] == 'e')
	{
		ary[4][0]++;
	}
	sum[4][0] = ary[4][0];
	for (int i = 1; i < num2; i++)
	{
		if (str[i] == 'e')
		{
			ary[4][i]++;
		}
		sum[4][i] = ary[4][i] + sum[4][i - 1];
	}
	if (str[0] == 'f')
	{
		ary[5][0]++;
	}
	sum[5][0] = ary[5][0];
	for (int i = 1; i < num2; i++)
	{
		if (str[i] == 'f')
		{
			ary[5][i]++;
		}
		sum[5][i] = ary[5][i] + sum[5][i - 1];
	}
	if (str[0] == 'g')
	{
		ary[6][0]++;
	}
	sum[6][0] = ary[6][0];
	for (int i = 1; i < num2; i++)
	{
		if (str[i] == 'g')
		{
			ary[6][i]++;
		}
		sum[6][i] = ary[6][i] + sum[6][i - 1];
	}
	if (str[0] == 'h')
	{
		ary[7][0]++;
	}
	sum[7][0] = ary[7][0];
	for (int i = 1; i < num2; i++)
	{
		if (str[i] == 'h')
		{
			ary[7][i]++;
		}
		sum[7][i] = ary[7][i] + sum[7][i - 1];
	}

	if (str[0] == 'i')
	{
		ary[8][0]++;
	}
	sum[8][0] = ary[8][0];
	for (int i = 1; i < num2; i++)
	{
		if (str[i] == 'i')
		{
			ary[8][i]++;
		}
		sum[8][i] = ary[8][i] + sum[8][i - 1];
	}
	if (str[0] == 'j')
	{
		ary[9][0]++;
	}
	sum[9][0] = ary[9][0];
	for (int i = 1; i < num2; i++)
	{
		if (str[i] == 'j')
		{
			ary[9][i]++;
		}
		sum[9][i] = ary[9][i] + sum[9][i - 1];
	}

	if (str[0] == 'k')
	{
		ary[10][0]++;
	}
	sum[10][0] = ary[10][0];
	for (int i = 1; i < num2; i++)
	{
		if (str[i] == 'k')
		{
			ary[10][i]++;
		}
		sum[10][i] = ary[10][i] + sum[10][i - 1];
	}
	if (str[0] == 'l')
	{
		ary[11][0]++;
	}
	sum[11][0] = ary[11][0];
	for (int i = 1; i < num2; i++)
	{
		if (str[i] == 'l')
		{
			ary[11][i]++;
		}
		sum[11][i] = ary[11][i] + sum[11][i - 1];
	}
	if (str[0] == 'm')
	{
		ary[12][0]++;
	}
	sum[12][0] = ary[12][0];
	for (int i = 1; i < num2; i++)
	{
		if (str[i] == 'm')
		{
			ary[12][i]++;
		}
		sum[12][i] = ary[12][i] + sum[12][i - 1];
	}

	if (str[0] == 'n')
	{
		ary[13][0]++;
	}
	sum[13][0] = ary[13][0];
	for (int i = 1; i < num2; i++)
	{
		if (str[i] == 'n')
		{
			ary[13][i]++;
		}
		sum[13][i] = ary[13][i] + sum[13][i - 1];
	}

	if (str[0] == 'o')
	{
		ary[14][0]++;
	}
	sum[14][0] = ary[14][0];
	for (int i = 1; i < num2; i++)
	{
		if (str[i] == 'o')
		{
			ary[14][i]++;
		}
		sum[14][i] = ary[14][i] + sum[14][i - 1];
	}

	if (str[0] == 'p')
	{
		ary[15][0]++;
	}
	sum[15][0] = ary[15][0];
	for (int i = 1; i < num2; i++)
	{
		if (str[i] == 'p')
		{
			ary[15][i]++;
		}
		sum[15][i] = ary[15][i] + sum[15][i - 1];
	}
	if (str[0] == 'q')
	{
		ary[16][0]++;
	}
	sum[16][0] = ary[16][0];
	for (int i = 1; i < num2; i++)
	{
		if (str[i] == 'q')
		{
			ary[16][i]++;
		}
		sum[16][i] = ary[16][i] + sum[16][i - 1];
	}
	if (str[0] == 'r')
	{
		ary[17][0]++;
	}
	sum[17][0] = ary[17][0];
	for (int i = 1; i < num2; i++)
	{
		if (str[i] == 'r')
		{
			ary[17][i]++;
		}
		sum[17][i] = ary[17][i] + sum[17][i - 1];
	}
	if (str[0] == 's')
	{
		ary[18][0]++;
	}
	sum[18][0] = ary[18][0];
	for (int i = 1; i < num2; i++)
	{
		if (str[i] == 's')
		{
			ary[18][i]++;
		}
		sum[18][i] = ary[18][i] + sum[18][i - 1];
	}
	if (str[0] == 't')
	{
		ary[19][0]++;
	}
	sum[19][0] = ary[19][0];
	for (int i = 1; i < num2; i++)
	{
		if (str[i] == 't')
		{
			ary[19][i]++;
		}
		sum[19][i] = ary[19][i] + sum[19][i - 1];
	}
	if (str[0] == 'u')
	{
		ary[20][0]++;
	}
	sum[20][0] = ary[20][0];
	for (int i = 1; i < num2; i++)
	{
		if (str[i] == 'u')
		{
			ary[20][i]++;
		}
		sum[20][i] = ary[20][i] + sum[20][i - 1];
	}
	if (str[0] == 'v')
	{
		ary[21][0]++;
	}
	sum[21][0] = ary[21][0];
	for (int i = 1; i < num2; i++)
	{
		if (str[i] == 'v')
		{
			ary[21][i]++;
		}
		sum[21][i] = ary[21][i] + sum[21][i - 1];
	}
	if (str[0] == 'w')
	{
		ary[22][0]++;
	}
	sum[22][0] = ary[22][0];
	for (int i = 1; i < num2; i++)
	{
		if (str[i] == 'w')
		{
			ary[22][i]++;
		}
		sum[22][i] = ary[22][i] + sum[22][i - 1];
	}
	if (str[0] == 'x')
	{
		ary[23][0]++;
	}
	sum[23][0] = ary[23][0];
	for (int i = 1; i < num2; i++)
	{
		if (str[i] == 'x')
		{
			ary[23][i]++;
		}
		sum[23][i] = ary[23][i] + sum[23][i - 1];
	}
	if (str[0] == 'y')
	{
		ary[24][0]++;
	}
	sum[24][0] = ary[24][0];
	for (int i = 1; i < num2; i++)
	{
		if (str[i] == 'y')
		{
			ary[24][i]++;
		}
		sum[24][i] = ary[24][i] + sum[24][i - 1];
	}

	if (str[0] == 'z')
	{
		ary[25][0]++;
	}
	sum[25][0] = ary[25][0];
	for (int i = 1; i < num2; i++)
	{
		if (str[i] == 'z')
		{
			ary[25][i]++;
		}
		sum[25][i] = ary[25][i] + sum[25][i - 1];
	}

	for (int i = 0; i < num1; i++)
	{
		int start = 0;
		int end = 0;
		char target[5];

		scanf("%s %d %d", target, &start, &end);
		printf("%d\n", sum[target[0] - 97][end] - sum[target[0] - 97][start - 1]);
		
	}
}