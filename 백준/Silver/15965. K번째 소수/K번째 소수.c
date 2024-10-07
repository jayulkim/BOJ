#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[8000001] = { 0, };
int ary1[8000001] = { 0, };

int main(void)
{
	int num1 = 0;
	int index = 0;


	
	scanf("%d", &num1);

	for (int i = 2; i < 8000001; i++)
	{
		ary[i] = i;
	}
	for (int i = 2; i < 8000001; i++)
	{
		if (ary[i] != 0)
		{
			for (int j = i * 2; j  < 8000001; j += i)
			{
				ary[j] = 0;
			}
			ary1[index] = ary[i];
			index++;
		}

	}



	printf("%d\n", ary1[num1 - 1]);
	


}
