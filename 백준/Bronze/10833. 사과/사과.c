#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

typedef struct info
{
	int student;
	int apple;
}info;

info list[105];

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	int sum = 0;
	for (int i = 0; i < num1; i++)
	{
		scanf("%d %d", &list[i].student, &list[i].apple);
		sum += (list[i].apple % list[i].student);
	}
	printf("%d\n", sum);

}