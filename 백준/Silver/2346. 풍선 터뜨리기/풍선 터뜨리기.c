#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ary[1005] = { 0, };

typedef struct info
{
	int number;
	int index;
}info;

typedef struct Dq
{
	int headdown;
	int headup;
	int size;
	info* dq;
}Dq;

Dq* create(int size)
{
	Dq* new = (Dq*)malloc(sizeof(Dq));
	new->headdown = 0;
	new->headup = 0;
	new->size = size + 1;
	new->dq = (info*)malloc(sizeof(info) * new->size);
	return new;
}

int empty(Dq* dq)
{
	if (dq->headdown == dq->headup)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int full(Dq* dq)
{
	if (dq->headdown == (dq->headup + 1) % dq->size)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void front_push(Dq* dq, int num, int index)
{
	if (full(dq) == 1)
	{
		return;
	}
	dq->dq[dq->headdown].number = num;
	dq->dq[dq->headdown].index = index;
	dq->headdown = (dq->headdown - 1 + dq->size) % dq->size;
}

info front_pop(Dq* dq)
{
	if (empty(dq) == 1)
	{
		return;
	}
	dq->headdown = (dq->headdown + 1) % dq->size;
	return dq->dq[dq->headdown];
}

void back_push(Dq* dq, int num, int index)
{
	if (full(dq) == 1)
	{
		return;
	}
	dq->headup = (dq->headup + 1) % dq->size;
	dq->dq[dq->headup].number = num;
	dq->dq[dq->headup].index = index;
}

info back_pop(Dq* dq)
{
	if (empty(dq) == 1)
	{
		return;
	}
	int pop = dq->headup;
	dq->headup = (dq->headup - 1 + dq -> size) % dq->size;
	return dq->dq[pop];
}

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	Dq* list = create(num1);
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary[i]);
		back_push(list, ary[i], i + 1);
	}

	printf("1 ");
	int index1 = front_pop(list).number;
	num1--;
	while (num1--)
	{
		if (index1 > 0)
		{
			for (int i = 0; i < index1 - 1; i++)
			{
				int num3 = front_pop(list).number;
				int num2 = list->dq[list->headdown].index;
				back_push(list, num3, num2);
			}	
			printf("%d ", front_pop(list).index);
			index1 = list -> dq[list -> headdown].number;
		}
		else if (index1 < 0)
		{
			for (int i = 0; i < -index1 - 1; i++)
			{
				int num4 = list->dq[list->headup].index;
				int num5 = back_pop(list).number;
				front_push(list, num5, num4);
			}
			printf("%d ", list->dq[list->headup].index);
			index1 = back_pop(list).number;
		}
	}
	free(list->dq);
	free(list);
}
	



