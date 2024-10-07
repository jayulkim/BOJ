#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary2[4] = { 2, 3,5, 7 };

int main(void)
{
	int num1 = 0;
	
	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		int num2 = 0;
		int ary[1000] = { 0, };
		int ary1[1000] = {0, };
		scanf("%d", &num2);

		int count = 1;

		int index = 0;
		int index2 = 0;
		if (num2 % ary2[0] == 0 || num2 % ary2[1] == 0 || num2 % ary2[2] == 0 || num2 % ary2[3] == 0)
		{

		}
		while (num2 != 1)
		{
			if (num2 % ary2[index2] == 0)
			{
				ary[index] = ary2[index2];
				index++;
				num2 /= ary2[index2];
			}
			else
			{
				index2++;
			}
			if (index2 > 3)
			{
				printf("-1\n");
				break;
			}

		}

		
		if (index2 <= 3)
		{
			int index1 = 0;
			int index2 = 0;
			ary1[index1]++;
			while (index2 <= index - 1)
			{
				if (ary1[index1] * ary[index2] < 10)
				{
					ary1[index1] = ary1[index1] * ary[index2];
					index2++;
				}
				else
				{
					index1++;
					ary1[index1]++;
				}
			}
			printf("%d\n", index1 + 1);
			

		}


	}

	
} 