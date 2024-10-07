#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long int ary[60] = { 0, };

int compare(const void* num1, const void* num2)
{
	long long int a = *(long long int*)num1;
	long long int b = *(long long int*)num2;
	if (a > b)
	{
		return 1;
	}
	else if (a < b)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int main(void)
{
	int num1 = 0;

	int zero = 60;
	int plus = 0;
	int minus = 0;

	long long int result = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		scanf("%lld", &ary[i]);
		if (ary[i] < 0)
		{
			minus++;
		}
		else if (ary[i] > 0)
		{
			plus++;
		}
	}
	qsort(ary, num1, sizeof(long long int), compare);

	for (int i = 0; i < num1; i++)
	{
		if (ary[i] == 0)
		{
			zero = i;
		}
	}
	if (plus % 2 == 0 && minus % 2 == 0)
	{

		for (int i = num1 - 1; i >= 0; i -= 2)
		{
			if (ary[i] <= 0)
			{
				break;
			}
			if (ary[i] * ary[i - 1] > ary[i] + ary[i-1])
			{
				result += (ary[i] * ary[i - 1]);
			}
			else
			{
				result += (ary[i] + ary[i - 1]);
			}

		}
		//	printf("%d\n", result);
		for (int i = 0; i < num1; i += 2)
		{
			if (ary[i] >= 0)
			{
				break;
			}
			//printf("%d %d\n", ary[i], ary[i + 1]);
			if (ary[i] * ary[i + 1] > ary[i] + ary[i+1])
			{
				result += (ary[i] * ary[i + 1]);
			}
			else
			{
				result += (ary[i] + ary[i + 1]);
			}
			

		}
		printf("%lld\n", result);
	}
	else if (minus % 2 == 0 && plus % 2 == 1)
	{
		for (int i = num1 - 1; i >= 0; i -= 2)
		{
			if (ary[i - 1] <= 0)
			{
				result += ary[i];
				break;
			}
			if (ary[i] * ary[i - 1] > ary[i] + ary[i - 1])
			{
				result += (ary[i] * ary[i - 1]);
			}
			else
			{
				result += (ary[i] + ary[i - 1]);
			}
		}
	//	printf("%d\n", result);
		for (int i = 0; i < num1; i += 2)
		{
			if (ary[i] >= 0)
			{
				break;
			}
			//printf("%d %d\n", ary[i], ary[i + 1]);
			if (ary[i] * ary[i + 1] > ary[i] + ary[i + 1])
			{
				result += (ary[i] * ary[i + 1]);
			}
			else
			{
				result += (ary[i] + ary[i + 1]);
			}
		}
		printf("%lld\n", result);
	}
	else if (minus % 2 == 1 && plus % 2 == 0)
	{
		if (zero == 60)
		{
			for (int i = num1 - 1; i >= 0; i -= 2)
			{
				if (ary[i] <= 0)
				{
					break;
				}
				if (ary[i] * ary[i - 1] > ary[i] + ary[i - 1])
				{
					result += (ary[i] * ary[i - 1]);
				}
				else
				{
					result += (ary[i] + ary[i - 1]);
				}
			}
			for (int i = 0; i < num1; i += 2)
			{
				if (ary[i + 1] >= 0)
				{
					result += ary[i];
					break;
				}
				//printf("%d %d\n", ary[i], ary[i + 1]);
				if (ary[i] * ary[i + 1] > ary[i] + ary[i + 1])
				{
					result += (ary[i] * ary[i + 1]);
				}
				else
				{
					result += (ary[i] + ary[i + 1]);
				}

			}
			printf("%lld\n", result);
		}
		else
		{
			for (int i = num1 - 1; i >= 0; i -= 2)
			{
				if (ary[i] <= 0)
				{
					break;
				}
				if (ary[i] * ary[i - 1] > ary[i] + ary[i - 1])
				{
					result += (ary[i] * ary[i - 1]);
				}
				else
				{
					result += (ary[i] + ary[i - 1]);
				}
			}
			for (int i = 0; i < num1; i += 2)
			{
				if (ary[i + 1] >= 0)
				{
					break;
				}
				//printf("%d %d\n", ary[i], ary[i + 1]);
				if (ary[i] * ary[i + 1] > ary[i] + ary[i + 1])
				{
					result += (ary[i] * ary[i + 1]);
				}
				else
				{
					result += (ary[i] + ary[i + 1]);
				}
			}
			printf("%lld\n", result);

		}
		
	}
	else if (minus % 2 == 1 && plus % 2 == 1)
	{
		if (zero == 60)
		{
			for (int i = num1 - 1; i >= 0; i -= 2)
			{
				if (ary[i - 1] <= 0)
				{
					result += ary[i];
					break;
				}
				if (ary[i] * ary[i - 1] > ary[i] + ary[i - 1])
				{
					result += (ary[i] * ary[i - 1]);
				}
				else
				{
					result += (ary[i] + ary[i - 1]);
				}

			}
			for (int i = 0; i < num1; i += 2)
			{
				if (ary[i + 1] >= 0)
				{
					result += ary[i];
					break;
				}
				//printf("%d %d\n", ary[i], ary[i + 1]);
				if (ary[i] * ary[i + 1] > ary[i] + ary[i + 1])
				{
					result += (ary[i] * ary[i + 1]);
				}
				else
				{
					result += (ary[i] + ary[i + 1]);
				}
			

			}
			printf("%lld\n", result);
		}
		else
		{
			for (int i = num1 - 1; i >= 0; i -= 2)
			{
				if (ary[i - 1] <= 0)
				{
					result += ary[i];
					break;
				}
				if (ary[i] * ary[i - 1] > ary[i] + ary[i - 1])
				{
					result += (ary[i] * ary[i - 1]);
				}
				else
				{
					result += (ary[i] + ary[i - 1]);
				}

			}
			for (int i = 0; i < num1; i += 2)
			{
				if (ary[i + 1] >= 0)
				{
					break;
				}
				//printf("%d %d\n", ary[i], ary[i + 1]);
				if (ary[i] * ary[i + 1] > ary[i] + ary[i + 1])
				{
					result += (ary[i] * ary[i + 1]);
				}
				else
				{
					result += (ary[i] + ary[i + 1]);
				}
			}
			printf("%lld\n", result);
		}
	}

}