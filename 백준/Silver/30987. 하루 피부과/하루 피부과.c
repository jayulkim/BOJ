#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int x1 = 0;
	int x2 = 0;
	scanf("%d %d", &x1, &x2);

	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

	printf("%d\n", a / 3 * (x2 * x2 * x2 - x1 * x1 * x1) + (b - d) / 2 * (x2 * x2 - x1 * x1) + (c - e) * (x2 - x1));
}