#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void)
{
	char str1[100];
	gets(str1);

	printf(":fan::fan::fan:\n:fan::%s::fan:\n:fan::fan::fan:", str1);

}