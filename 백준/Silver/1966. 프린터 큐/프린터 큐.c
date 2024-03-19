#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct info
{
	int count;
	int index;
}info;

info ary[105];

info que[10005];
int headdown = 0;
int headup = -1;

int empry(info* que)
{
	if (headdown == headup + 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void pushup(info* que, int count, int index)
{
	que[++headup].count = count;
	que[headup].index = index;
}

info popdown(info* que)
{
	return que[headdown++];
}

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		int num2 = 0;
		int num3 = 0;
		scanf("%d %d", &num2, &num3);
		for (int j = 0; j < num2; j++)
		{
			scanf("%d", &ary[j].count);
			ary[j].index = j;
			pushup(que, ary[j].count, ary[j].index);
		}

		int result = 1;
		while (1)
		{
			int index1 = 0;
			int count1 = 0;
			for (int j = headdown + 1; j <= headup; j++)
			{
				if (que[headdown].count < que[j].count)
				{
					index1 = j;
					count1++;
					break;
				}
			}

			if (count1 == 0)
			{
				if (que[headdown].index == num3)
				{
					printf("%d\n", result);
					break;
				}
				popdown(que);
				result++;
			}
			else
			{
				for (int j = headdown; j < index1; j++)
				{
					pushup(que, que[headdown].count, que[headdown].index);
					popdown(que);
				}
			}	
		}
		headdown = 0;
		headup = -1;
	}
}