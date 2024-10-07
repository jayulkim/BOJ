#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char map[600][600];


int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	
	scanf("%d %d %d", &num1, &num2, &num3);

	int sum = 0;

	for (int i = 0; i < num1; i++)
	{
		scanf("%s", map[i]);

	}
	for (int m = 0; m < num3; m++)
	{
		for (int h = 0; h < num3; h++)
		{
			int ary[600] = { 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
			for (int j = m; j < num1; j += num3)
			{
				for (int i = h; i < num2; i += num3)
				{
					if (map[j][i] == 'A')
					{
						ary[0]++;
					}
					else if (map[j][i] == 'B')
					{
						ary[1]++;
					}
					else if (map[j][i] == 'C')
					{
						ary[2]++;
					}
					else if (map[j][i] == 'D')
					{
						ary[3]++;
					}
					else if (map[j][i] == 'E')
					{
						ary[4]++;
					}
					else if (map[j][i] == 'F')
					{
						ary[5]++;
					}
					else if (map[j][i] == 'G')
					{
						ary[6]++;
					}
					else if (map[j][i] == 'H')
					{
						ary[7]++;
					}
					else if (map[j][i] == 'I')
					{
						ary[8]++;
					}
					else if (map[j][i] == 'J')
					{
						ary[9]++;
					}
					else if (map[j][i] == 'K')
					{
						ary[10]++;
					}
					else if (map[j][i] == 'L')
					{
						ary[11]++;
					}
					else if (map[j][i] == 'M')
					{
						ary[12]++;
					}
					else if (map[j][i] == 'N')
					{
						ary[13]++;
					}
					else if (map[j][i] == 'O')
					{
						ary[14]++;
					}
					else if (map[j][i] == 'P')
					{
						ary[15]++;
					}
					else if (map[j][i] == 'Q')
					{
						ary[16]++;
					}
					else if (map[j][i] == 'R')
					{
						ary[17]++;
					}
					else if (map[j][i] == 'S')
					{
						ary[18]++;
					}
					else if (map[j][i] == 'T')
					{
						ary[19]++;
					}
					else if (map[j][i] == 'U')
					{
						ary[20]++;
					}
					else if (map[j][i] == 'V')
					{
						ary[21]++;
					}
					else if (map[j][i] == 'W')
					{
						ary[22]++;
					}
					else if (map[j][i] == 'X')
					{
						ary[23]++;
					}
					else if (map[j][i] == 'Y')
					{
						ary[24]++;
					}
					else if (map[j][i] == 'Z')
					{
						ary[25]++;
					}
				}
			}
			int max = 0;
			int index = 0;
			for (int n = 0; n < 30; n++)
			{
				if (ary[n] >= max)
				{
					max = ary[n];
					index = n;
				}
			}
			
			for (int n = 0; n < 26 ; n++)
			{
				if (n != index)
				{
					sum += ary[n];
				}
				
				//printf("%d ", n);
			}
			//printf("%d %d\n", index, ary[2]);
			for (int j = m; j < num1; j += num3)
			{
				for (int i = h; i < num2; i += num3)
				{
					if (index == 0)
					{
						map[j][i] = 'A';
					}
					else if (index == 1)
					{
						map[j][i] = 'B';
					}
					else if (index == 2)
					{
						map[j][i] = 'C';
					}
					else if (index == 3)
					{
						map[j][i] = 'D';
					}
					else if (index == 4)
					{
						map[j][i] = 'E';
					}
					else if (index == 5)
					{
						map[j][i] = 'F';
					}
					else if (index == 6)
					{
						map[j][i] = 'G';
					}
					else if (index == 7)
					{
						map[j][i] = 'H';
					}
					else if (index == 8)
					{
						map[j][i] = 'I';
					}
					else if (index == 9)
					{
						map[j][i] = 'J';
					}
					else if (index == 10)
					{
						map[j][i] = 'K';
					}
					else if (index == 11)
					{
						map[j][i] = 'L';
					}
					else if (index == 12)
					{
						map[j][i] = 'M';
					}
					else if (index == 13)
					{
						map[j][i] = 'N';
					}
					else if (index == 14)
					{
						map[j][i] = 'O';
					}
					else if (index == 15)
					{
						map[j][i] = 'P';
					}
					else if (index == 16)
					{
						map[j][i] = 'Q';
					}
					else if (index == 17)
					{
						map[j][i] = 'R';
					}
					else if (index == 18)
					{
						map[j][i] = 'S';
					}
					else if (index == 19)
					{
						map[j][i] = 'T';
					}
					else if (index == 20)
					{
						map[j][i] = 'U';
					}
					else if (index == 21)
					{
						map[j][i] = 'V';
					}
					else if (index == 22)
					{
						map[j][i] = 'W';
					}
					else if (index == 23)
					{
						map[j][i] = 'X';
					}
					else if (index == 24)
					{
						map[j][i] = 'Y';
					}
					else if (index == 25)
					{
						map[j][i] = 'Z';
					}
				}
			}
		}
	}
	printf("%d\n", sum);
	for (int i = 0; i < num1; i++)
	{
		printf("%s\n", map[i]);
		
	}

}