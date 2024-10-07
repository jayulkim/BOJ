#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int compare(const void* num1, const void* num2) 
{
  double a = *(double*)num1;
  double b = *(double*)num2;
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
	double x1 = 0;
	double y1 = 0;
	
	double x2 = 0;
	double y2 = 0;

	double x3 = 0;
	double y3 = 0;

	scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
	double distence[3] = { 0, };

	distence[0] = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	distence[1] = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
	distence[2] = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
	
	qsort(distence, 3, sizeof(double), compare);

	if ((x1 - x2) != 0 && (x3 - x2) != 0 && (x1 - x3) != 0)
	{
		if ((y1 - y2) / (x1 - x2) == (y1 - y3) / (x1 - x3) && (y1 - y3) / (x1 - x3) == (y2 - y3) / (x2 - x3))
		{
			printf("-1.0\n");
		}
		else
		{
			printf("%.30lf\n", 2 * distence[2] + 2 * distence[1] - 2 * distence[1] - 2 * distence[0]);
		}
	}
	else if ((x1 - x2) == 0 && (x3 - x2) != 0)
	{
		printf("%.30lf\n", 2 * distence[2] + 2 * distence[1] - 2 * distence[1] - 2 * distence[0]);
	}
	else if ((x1 - x3) == 0 && (x3 - x2) != 0)
	{
		printf("%.30lf\n", 2 * distence[2] + 2 * distence[1] - 2 * distence[1] - 2 * distence[0]);
	}
	else if ((x2 - x3) == 0 && (x3 - x1) != 0)
	{
		printf("%.30lf\n", 2 * distence[2] + 2 * distence[1] - 2 * distence[1] - 2 * distence[0]);
	}
	else if ((x2 - x3) == 0 && (x3 - x1) == 0)
	{
		printf("-1.0\n");
	}
	

}