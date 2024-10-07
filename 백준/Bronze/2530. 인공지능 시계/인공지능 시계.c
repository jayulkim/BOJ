#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


int main(void)
{
	int hour = 0;
	int min = 0;
	int sec = 0;
	scanf("%d %d %d", &hour, &min, &sec);

	int time = 0;
	scanf("%d", &time);

	int num1 = time % 60;
	int num2 = time / 60;
	int num3 = time % 3600;
	int num4 = time / 3600;

	sec += num1;
	
	time -= num1;

	min += (sec / 60 + time / 60);
	sec %= 60;

	time -= (num2 * 60);
	//printf("%d\n", time);
	hour += (min / 60 + time);
	min %= 60;
	hour %= 24;
	printf("%d %d %d", hour, min, sec);
}