#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct info
{
	long long int number;
	long long int transnumber;
}info;

info list[1005];
info list1[1005];

int compare(const void* num1, const void* num2)
{
	info *a = (info*)num1;
	info* b = (info*)num2;

	if (a -> transnumber > b -> transnumber)
	{
		return -1;
	}
	else if (a->transnumber < b->transnumber)
	{
		return 1;
	}
	else
	{
		if (a->number > b->number)
		{
			return -1;
		}
		else if (a->number < b->number)
		{
			return 1;
		}
		else
		{
			return 0;
		}
		
	}
}

int compare1(const void* num1, const void* num2)
{
	info* a = (info*)num1;
	info* b = (info*)num2;
	if (a->number > b->number)
	{
		return 1;
	}
	else if (a->number < b->number)
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
	int num4 = 0;
	scanf("%d %d", &num1, &num4);
	long long int max = 0;

	for (int i = 0; i < num1; i++)
	{
		scanf("%lld", &list[i].number);
		
	}
	qsort(list, num1, sizeof(info), compare1);

	for (int i = 0; i < num4; i++)
	{
		list1[i].number = list[i].number;
		list1[i].transnumber = list[i].number;

		if (i >= num1)
		{
			list1[i].number = list[num1 - 1].number;
			list1[i].transnumber = list[num1 - 1].number;
		}
		if (max < list1[i].number)
		{
			max = list1[i].number;
		}
		//printf("%lld ", list1[i].number);

	}
	if (max == 0)
	{
		printf("0\n");
		return 0;
	}

	for (int i = 0; i < num4; i++)
	{
		long long int num2 = list1[i].number;
		if (num2 == 0)
		{
			list1[i].transnumber = 0;
		}
		else
		{
			long long int ary1[15] = { 0, };
			int index = 0;
			int len1 = 0;
			while (num2 >= 1)
			{
				len1++;
				ary1[index] = num2 % 10;
				//	printf("%d\n", ary1[index]);
				index++;
				num2 /= 10;
			}
			for (int j = len1; j < 10; j++)
			{

				list1[i].transnumber *= 10;
				list1[i].transnumber += ary1[index - 1];
				index--;
				if (index == 0)
				{
					index = len1;
				}
			}
		}
		
	}
	qsort(list1, num4, sizeof(info), compare);

	for (int i = 0; i < num4; i++)
	{
	//	printf("%lld ", list[i].transnumber);
		printf("%lld", list1[i].number);
	}

}