#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct info
{
	char str[10];
	int len;
}info;

info list[15];

int ary[30];

int compare(const void* num1, const void* num2)
{
	info* a = (info*)num1;
	info* b = (info*)num2;

	if (a->len > b->len)
	{
		return -1;
	}
	else if (a->len < b->len)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


char map[15][15];

typedef struct word
{
	int number;
	int count;
	char c;
}word;

word ary1[30];

int compare1(const void* num1, const void* num2)
{
	word* a = (word*)num1;
	word* b = (word*)num2;

	if (a->count > b->count)
	{
		return -1;
	}
	else if (a->count < b->count)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main(void)
{
	//printf("%d %d %d %d", 'A', 'Z', '0', '9');

	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		scanf("%s", list[i].str);
		list[i].len = strlen(list[i].str);
	}
	qsort(list, num1, sizeof(info), compare);

	int count1 = 57;
	for (int i = 0; i < num1; i++)
	{
		int len1 = strlen(list[i].str);
		for (int j = list[0].len - 1; j >= 0; j--)
		{
			map[i][j] = list[i].str[len1 - 1];
			len1--;
			if (len1 < 0)
			{
				break;
			}
		}
	}
	int num3 = 1;
	for (int i = 0; i < list[0].len - 1; i++)
	{
		num3 *= 10;
	}

	for (int j = 0; j < list[0].len; j++)
	{
		for (int k = 0; k < num1; k++)
		{
			if (map[k][j] != '\0')
			{
				ary1[map[k][j] - 65].count += num3;
				ary1[map[k][j] - 65].c = map[k][j];
			}
		}
		num3 /= 10;
	}
	qsort(ary1, 30, sizeof(word), compare1);
	
	for (int i = 0; i < 30; i++)
	{
	//	printf("%d %c\n", ary1[i].count, ary1[i].c);

	}
	for (int j = 0; j < list[0].len; j++)
	{
		for (int k = 0; k < num1; k++)
		{
			if (map[k][j] != '\0')
			{
				if (isdigit(map[k][j]) == 0)
				{
					for (int i = 0; i < 30; i++)
					{
						if (ary1[i].count != 0)
						{
							if (map[k][j] == ary1[i].c)
							{
								ary1[i].number = count1 - i;
								map[k][j] = count1 - i;
								break;
							}
						}
					}
				}
				else
				{
					for (int i = 0; i < 30; i++)
					{
						if (ary1[i].count != 0)
						{
							if (map[k][j] == ary1[i].c)
							{
								map[k][j] = ary1[i].number;
								break;
							}
						}
					}
				}
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < num1; i++)
	{
		int index = 0;
		for (int j = 0; j < list[0].len; j++)
		{
			if (map[i][j] != '\0')
			{
		//		printf("%c", map[i][j]);
				index = j;
				break;
			}
			else
			{
		//		printf(" ");
			}
		}
		int num2 = atoi(&map[i][index]);
		sum += num2;
	//	printf("%d\n", num2);
	//	printf("\n");
	}
	printf("%d", sum);
}