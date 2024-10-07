#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct info
{
	int day;
	int hurry;
	int linenumber;
	int number;
}info;

info list[100005];

typedef struct Heap
{
	int size;
	info heap[100005];
}Heap;

Heap* create()
{
	return (Heap*)malloc(sizeof(Heap));
}

void init(Heap* h)
{
	h->size = 0;
}
void swap(info* num1, info* num2)
{
	info temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
void insertday(Heap* dayh, info day)
{
	int size = ++(dayh->size);
	dayh->heap[size] = day;
	while (size != 1)
	{
		if (dayh->heap[size].day > dayh->heap[size / 2].day)
		{
			swap(&dayh->heap[size], &dayh->heap[size / 2]);
			size /= 2;
		}
		else if (dayh->heap[size].day == dayh->heap[size / 2].day)
		{
			if (dayh->heap[size].hurry > dayh->heap[size / 2].hurry)
			{
				swap(&dayh->heap[size], &dayh->heap[size / 2]);
				size /= 2;
			}
			else if (dayh->heap[size].hurry == dayh->heap[size / 2].hurry)
			{
				if (dayh->heap[size].linenumber < dayh->heap[size / 2].linenumber)
				{
					swap(&dayh->heap[size], &dayh->heap[size / 2]);
					size /= 2;
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
		else
		{
			break;
		}
	}
}
info deleteday(Heap* dayh)
{
	info root = dayh->heap[1];
	int parent = 1;
	int child = 2;
	info temp = dayh->heap[dayh->size--];
	dayh->heap[1] = temp;
	while (child <= dayh->size)
	{
		if (child < dayh->size)
		{
			if (dayh->heap[child].day < dayh->heap[child + 1].day)
			{
				child++;
			}
			else if (dayh->heap[child].day == dayh->heap[child + 1].day)
			{
				if (dayh->heap[child].hurry < dayh->heap[child + 1].hurry)
				{
					child++;
				}
				else if (dayh->heap[child].hurry == dayh->heap[child + 1].hurry)
				{
					if ((dayh->heap[child].linenumber > dayh->heap[child + 1].linenumber))
					{
						child++;
					}
				}
			}
		}
		if (temp.day > dayh->heap[child].day)
		{
			break;
		}
		else if (temp.day == dayh->heap[child].day)
		{
			if (temp.hurry > dayh->heap[child].hurry)
			{
				break;
			}
			else if (temp.hurry == dayh->heap[child].hurry)
			{
				if (temp.linenumber < dayh->heap[child].linenumber)
				{
					break;
				}
			}
		}
		swap(&dayh->heap[child], &dayh->heap[parent]);
		parent = child;
		child *= 2;
	}
	return root;
}
int Min(int num1, int num2)
{
	if (num1 > num2)
	{
		return num2;
	}
	else
	{
		return num1;
	}
}

info daystack[100005];
int head = -1;
int empty()
{
	if (head == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void push(info* daystack, info del)
{
	daystack[++head] = del;
}
info pop(info* daystack)
{
	return daystack[head--];
}
void clear()
{
	head = -1;
}
int main(void)
{
	int member = 0;
	int line = 0;
	int target = 0;
	scanf("%d %d %d", &member, &line, &target);
	target++;
	for (int i = 1; i <= member; i++)
	{
		scanf("%d %d", &list[i].day, &list[i].hurry);
		list[i].number = i;
	}

	for (int j = 1; j <= line; j++)
	{
		if (j > member) 
		{
			break;
		}
		for (int i = j; i <= member; i += line)
		{
			list[i].linenumber = j;
		}
	}

	Heap* dayh = create();
	init(dayh);

	for (int i = 1; i <= Min(line, member); i++)
	{
		insertday(dayh, list[i]); 
	}
	int result = 0;
	
	while (1)
	{
		if (dayh->size > 0)
		{
			info delday = deleteday(dayh);
			if (delday.number == target)
			{
				printf("%d", result);
				return 0;
			}
			else
			{
				result++;
			}
			if (delday.number + Min(line, member) <= member)
			{
				push(daystack, list[delday.number + Min(line, member)]);
			}
		}
		while (empty() == 0)
		{
			insertday(dayh, pop(daystack));
		}
	}
}