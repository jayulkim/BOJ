#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int map[300][300] = { 0, };

typedef struct pos
{
	int jumnumber;
	int x;
	int y;
}pos;

pos list[100005];

int compare(const void* num1, const void* num2) 
{
  pos* a = (pos*)num1;
  pos* b = (pos*)num2;
  if (a -> jumnumber> b -> jumnumber)
  {
	  return 1;
  }
  else if (a->jumnumber < b->jumnumber)
  {
	  return -1;
  }
  else
  {
	  return 0;
  }

}

int lower_bound(pos* ary, int size, int key)
{
	int start = 0, end = size - 1;
	while (start < end)
	{
		int cen = (start + end) / 2;
		if (ary[cen].jumnumber >= key)
		{
			end = cen;
		}
		else
		{
			start = cen + 1;
		}
	}
	return end;
}

int main(void)
{
	int index = 1;
	for (int i = 1; i <= 292; i++)
	{
		int y = 1;
		for (int j = i; j <= 292; j++)
		{
			map[i][y] = i * (i + 1) / 2 + (j * (j - 1) / 2) - (i - 1) * i / 2;
			//printf("%d ", map[i][y]);
			list[index].jumnumber = i * (i + 1) / 2 + (j * (j - 1) / 2) - (i - 1) * i / 2;
			list[index].x = i;
			list[index].y = y;
			y++;
			index++;
		}
		//printf("\n");
	}
	qsort(list, index, sizeof(pos), compare);

	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		int num2 = 0;
		int num3 = 0;

		scanf("%d %d", &num2, &num3);
		
		int x1 = list[lower_bound(list, index, num2)].x;
		int y1 = list[lower_bound(list, index, num2)].y;

		int x2 = list[lower_bound(list, index, num3)].x;
		int y2 = list[lower_bound(list, index, num3)].y;

	//	printf("%d %d\n", x1, y1);

		printf("%d\n", map[x1 + x2][y1 + y2]);
	}
	
}