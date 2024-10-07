#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int compare(const void* num1, const void* num2) 
{
  int a = *(long long int*)num1;
  int b = *(long long int*)num2;
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
	double a = 0;
	double b = 0;
	double r = 0;

	double k = 0;
	double n = 0;
	double h = 0;

	double num1 = 0;
	double num2 = 0;
	scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &r, &k, &n, &h);
	
	if (r < h)
	{
		num1 = r;
		num2 = h;
	}
	else if (h <= r)
	{
		num1 = h;
		num2 = r;
	}
	double d = sqrt((a - k) * (a - k) + (b - n) * (b - n));
	if (r + h <= d)
	{
		printf("0.000");
	
	}
	else if (num1 + d <= num2)
	{
		printf("%.3lf", num1 * num1 * 3.14159265358979);
	}
	else if (r + h > d)
	{
		double p = 0.5 * (r + h + d);
		double s = sqrt(p * (p - r) * (p - h) * (p - d));
		double angle1 = acos((r * r + d * d - h * h) / (2 * r * d));
		double angle2 = acos((h * h + d * d - r * r) / (2 * h * d));

		double v1 = (2 * angle1 * r * r) / 2;
		double v2 = (2 * angle2 * h * h) / 2;
		printf("%.3lf", v1 + v2 - 2 * s);

	}
}