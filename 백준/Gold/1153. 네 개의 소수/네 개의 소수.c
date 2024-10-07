#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[1000005] = { 0, };

int main(void)
{
	for (int i = 2; i <= 1000000; i++)
	{
		if (ary[i] == 0)
		{
			for (int j = i * 2; j <= 1000000; j += i)
			{
				ary[j] = 1;
			}
		}
	}
	for (int i = 2; i <= 1000000; i++)
	{
		if (ary[i] == 0)
		{
		//	printf("%d ", i);
		}
		
	}
	int num1 = 0;
	scanf("%d", &num1);
	if (num1 < 8)
	{
		printf("-1\n");
		return 0;
	}

	int count = 0;

	int num2 = 0;
	int num3 = 0;
	if (num1 % 2 == 1)
	{
		int result1 = 0;
		int result2 = 0;
		int result3 = 0;
		int result4 = 0;

		int num4 = 4;
		
		while (1)
		{
			int num5 = num1 - num4;
			for (int i = 2; i <= num4; i++)
			{
				if (ary[i] == 0)
				{
					if (ary[num4 - i] == 0)
					{
						result1 = i;
						result2 = num4 - i;
						break;
					}
				}
			}
			for (int i = 2; i <= num5; i++)
			{
				if (ary[i] == 0)
				{
					if (ary[num5 - i] == 0)
					{
						result3 = i;
						result4 = num5 - i;
						break;
					}
				}
			}
			if (result1 != 0 && result2 != 0 && result3 != 0 && result4 != 0)
			{
				count++;
				printf("%d %d %d %d\n", result1, result2, result3, result4);
				break;
			}
			else
			{
				num4++;
			}
		}


	}
	else
	{
		if ((num1 / 2) % 2 == 0)
		{
			num2 = num1 / 2;
			num3 = num1 / 2;

			int result1 = 0;
			int result2 = 0;
			int result3 = 0;
			int result4 = 0;

			for (int i = 2; i <= num2; i++)
			{
				if (ary[i] == 0)
				{
					if (ary[num2 - i] == 0)
					{
						result1 = i;
						result2 = num2 - i;
						result3 = i;
						result4 = num2 - i;
						break;
					}
				}
			}
			count++;
			printf("%d %d %d %d\n", result1, result2, result3, result4);


		}
		else
		{
			int result1 = 0;
			int result2 = 0;
			int result3 = 0;
			int result4 = 0;
			int num4 = 4;
			
			while (1)
			{
				int num5 = num1 - num4;

				for (int i = 2; i <= num4; i++)
				{
					if (ary[i] == 0)
					{
						if (ary[num4 - i] == 0)
						{
							result1 = i;
							result2 = num4 - i;
							break;
						}
					}
				}
				for (int i = 2; i <= num5; i++)
				{
					if (ary[i] == 0)
					{
						if (ary[num5 - i] == 0)
						{
							result3 = i;
							result4 = num5 - i;
							break;
						}
					}
				}
				if (result1 != 0 && result2 != 0 && result3 != 0 && result4 != 0)
				{
					count++;
					printf("%d %d %d %d\n", result1, result2, result3, result4);
					break;
				}
				else
				{
					num4++;
				}
			}

		}
		if (count == 0)
		{
			printf("-1\n");
		}
	}

	

}