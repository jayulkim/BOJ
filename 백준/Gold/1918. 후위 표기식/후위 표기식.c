#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char wordstack[105];
char countstack[105];

int wordhead = -1;
int counthead = -1;

int wordempty()
{
	if (wordhead == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int countempty()
{
	if (counthead == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void wordpush(char* wordstack, char str)
{
	wordstack[++wordhead] = str;
}

void countpush(char* countstack, char str)
{
	countstack[++counthead] = str;
}

char wordpop(char* wordstack)
{
	return wordstack[wordhead--];
}
char countpop(char* countstack)
{
	return countstack[counthead--];
}

char wordptp(char* wordstack)
{
	return wordstack[wordhead];
}
char counttop(char* countstack)
{
	return countstack[counthead];
}

char str[105];

int main(void)
{
	scanf("%s", str);
	int num1 = strlen(str);
	for (int i = 0; i < num1; i++)
	{
		if (str[i] == '(')
		{
			countpush(countstack, str[i]);
		}
		else if (str[i] == '+' || str[i] == '-')
		{
			while (countempty() == 0 && counttop(countstack) != '(')
			{
				wordpush(wordstack, countpop(countstack));
			}
			countpush(countstack, str[i]);
		}
		else if (str[i] == '/' || str[i] == '*')
		{
			if ((counttop(countstack) == '/' || counttop(countstack) == '*') && countempty(countstack) == 0)
			{
				while (countempty() == 0 && (counttop(countstack) != '(' && counttop(countstack) != '+' && counttop(countstack) != '-'))
				{
					wordpush(wordstack, countpop(countstack));
				}
			}
			countpush(countstack, str[i]);
		}
		else if (str[i] == ')')
		{
			while (countempty() == 0 && counttop(countstack) != '(')
			{
				wordpush(wordstack, countpop(countstack));
			}
			countpop(countstack);
		}
		else
		{
			wordpush(wordstack, str[i]);
		}
	}
	while (countempty() == 0)
	{
		wordpush(wordstack, countpop(countstack));
	}
	for (int i = 0; i <= wordhead; i++)
	{
		printf("%c", wordstack[i]);
	}
}
