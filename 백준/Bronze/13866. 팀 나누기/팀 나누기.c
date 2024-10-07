#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void* num1, const void* num2)
{
	return *(int*)num1 - *(int*)num2;
}
int ary[6] = { 0, };
int main(void)
{
	scanf("%d %d %d %d", &ary[0], &ary[1], &ary[2], &ary[3]);
	qsort(ary, 4, sizeof(int), compare);
	printf("%d", abs(ary[3] + ary[0] - ary[1] - ary[2]));
}