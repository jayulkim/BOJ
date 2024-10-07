#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int compare(const void* num1, const void* num2)
{
	return *(int*)num1 - *(int*)num2;
}
int ary[10] = { 0, };
int ary1[5] = { 0, };

int main(void)
{
	
	scanf("%d", &ary[0]);
	scanf("%d", &ary[1]);
	scanf("%d", &ary[2]);
	scanf("%d", &ary[3]);
	scanf("%d", &ary1[0]);
	scanf("%d", &ary1[1]);
	qsort(ary, 4, sizeof(int), compare);
	qsort(ary1, 2, sizeof(int), compare);
	printf("%d", ary[3] + ary[2] + ary[1] + ary1[1]);
}