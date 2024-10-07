#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct pos
{
	double x;
	double y;
}pos;

pos list[5];

void swap(double* num1, double* num2)
{
	double c = *num1;
	*num1 = *num2;
	*num2 = c;
}

int compare(const void* num1, const void* num2)
{
	pos* a = (pos*)num1;
	pos* b = (pos*)num2;
	if (a->x > b->x)
	{
		return 1;
	}
	else if (a->x < b->x)
	{
		return -1;
	}
	else
	{
		if (a->y > b->y)
		{
			return 1;
		}
		else if (a->y < b->y)
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}
}

int main(void)
{
	scanf("%lf %lf %lf %lf %lf %lf", &list[0].x, &list[0].y, &list[1].x, &list[1].y, &list[2].x, &list[2].y);

	qsort(list, 3, sizeof(pos), compare);

	if (list[0].x == list[1].x)
	{
		double a = (list[1].y - list[2].y) / (list[1].x - list[2].x);
		double b = (list[1].y) - a * list[1].x;
		//printf("%lf %lf\n", a, b);
		double c = (list[2].y - list[0].y) / (list[2].x - list[0].x);
		double d = list[2].y - c * list[2].x;
	//	printf("%lf %lf\n", c, d);
		double result = (a - c) * (a - c) * (list[2].x * list[2].x * list[2].x - list[0].x * list[0].x * list[0].x);
		result /= 3;
		double result1 = result + (a - c) * (b - d) * (list[2].x * list[2].x - list[0].x * list[0].x) + (b - d) * (b - d) * (list[2].x - list[0].x);
		result *= 3.14159265358979323846264338327950288419716939937510582097494459230781;
		printf("%.6lf ", fabs(result));
	}
	else if (list[1].x == list[2].x)
	{
		double a = (list[2].y - list[0].y) / (list[2].x - list[0].x);
		double b = (list[2].y) - a * list[2].x;
		//printf("%lf %lf\n", a, b);
		double c = (list[1].y - list[0].y) / (list[1].x - list[0].x);
		double d = list[1].y - c * list[1].x;
		//	printf("%lf %lf\n", c, d);
		double result = (a - c) * (a - c) * (list[2].x * list[2].x * list[2].x - list[0].x * list[0].x * list[0].x);
		result /= 3;
		double result1 = result + (a - c) * (b - d) * (list[2].x * list[2].x - list[0].x * list[0].x) + (b - d) * (b - d) * (list[2].x - list[0].x);
		result *= 3.14159265358979323846264338327950288419716939937510582097494459230781;
		printf("%.6lf ", fabs(result));


	}
	else
	{
		double a = (list[1].y - list[0].y) / (list[1].x - list[0].x);
		double b = (list[0].y) - a * list[0].x;

		double c = (list[2].y - list[1].y) / (list[2].x - list[1].x);
		double d = (list[1].y) - c * list[1].x;

		double e = (list[2].y - list[0].y) / (list[2].x - list[0].x);
		double f = (list[2].y) - e * list[2].x;

		double t = a * a * (list[1].x * list[1].x * list[1].x - list[0].x * list[0].x * list[0].x);
		t /= 3;
		double result1 = t + a * b * (list[1].x * list[1].x - list[0].x * list[0].x) + b * b * (list[1].x - list[0].x);

		double t1 = c * c * (list[2].x * list[2].x * list[2].x - list[1].x * list[1].x * list[1].x);
		t1 /= 3;
		double result2 = t1 + c * d * (list[2].x * list[2].x - list[1].x * list[1].x) + d * d * (list[2].x - list[1].x);

		double t2 = e * e * (list[2].x * list[2].x * list[2].x - list[0].x * list[0].x * list[0].x);
		t2 /= 3;
		double result3 = t2 + e * f * (list[2].x * list[2].x - list[0].x * list[0].x) + f * f * (list[2].x - list[0].x);

		double result =result3 - result1 - result2;
		result *= 3.14159265358979323846264338327950288419716939937510582097494459230781;
		printf("%.6lf ", fabs(result));
	}
	swap(&list[0].x, &list[0].y);
	swap(&list[1].x, &list[1].y);
	swap(&list[2].x, &list[2].y);
	qsort(list, 3, sizeof(pos), compare);
	if (list[0].x == list[1].x)
	{
		double a = (list[1].y - list[2].y) / (list[1].x - list[2].x);
		double b = (list[1].y) - a * list[1].x;
		//printf("%lf %lf\n", a, b);
		double c = (list[2].y - list[0].y) / (list[2].x - list[0].x);
		double d = list[2].y - c * list[2].x;
		//	printf("%lf %lf\n", c, d);
		double result = (a - c) * (a - c) * (list[2].x * list[2].x * list[2].x - list[0].x * list[0].x * list[0].x);
		result /= 3;
		double result1 = result + (a - c) * (b - d) * (list[2].x * list[2].x - list[0].x * list[0].x) + (b - d) * (b - d) * (list[2].x - list[0].x);
		result *= 3.14159265358979323846264338327950288419716939937510582097494459230781;
		printf("%.6lf ", fabs(result));
	}
	else if (list[1].x == list[2].x)
	{
		double a = (list[2].y - list[0].y) / (list[2].x - list[0].x);
		double b = (list[2].y) - a * list[2].x;
		//printf("%lf %lf\n", a, b);
		double c = (list[1].y - list[0].y) / (list[1].x - list[0].x);
		double d = list[1].y - c * list[1].x;
		//	printf("%lf %lf\n", c, d);
		double result = (a - c) * (a - c) * (list[2].x * list[2].x * list[2].x - list[0].x * list[0].x * list[0].x);
		result /= 3;
		double result1 = result + (a - c) * (b - d) * (list[2].x * list[2].x - list[0].x * list[0].x) + (b - d) * (b - d) * (list[2].x - list[0].x);
		result *= 3.14159265358979323846264338327950288419716939937510582097494459230781;
		printf("%.6lf ", fabs(result));


	}
	else
	{
		double a = (list[1].y - list[0].y) / (list[1].x - list[0].x);
		double b = (list[0].y) - a * list[0].x;

		double c = (list[2].y - list[1].y) / (list[2].x - list[1].x);
		double d = (list[1].y) - c * list[1].x;

		double e = (list[2].y - list[0].y) / (list[2].x - list[0].x);
		double f = (list[2].y) - e * list[2].x;

		double t = a * a * (list[1].x * list[1].x * list[1].x - list[0].x * list[0].x * list[0].x);
		t /= 3;
		double result1 = t + a * b * (list[1].x * list[1].x - list[0].x * list[0].x) + b * b * (list[1].x - list[0].x);

		double t1 = c * c * (list[2].x * list[2].x * list[2].x - list[1].x * list[1].x * list[1].x);
		t1 /= 3;
		double result2 = t1 + c * d * (list[2].x * list[2].x - list[1].x * list[1].x) + d * d * (list[2].x - list[1].x);

		double t2 = e * e * (list[2].x * list[2].x * list[2].x - list[0].x * list[0].x * list[0].x);
		t2 /= 3;
		double result3 = t2 + e * f * (list[2].x * list[2].x - list[0].x * list[0].x) + f * f * (list[2].x - list[0].x);

		double result = result3 - result1 - result2;
		result *= 3.14159265358979323846264338327950288419716939937510582097494459230781;
		printf("%.6lf ", fabs(result));
	}
}