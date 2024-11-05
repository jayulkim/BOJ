#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int g=0,k=0, m=0, f=0, d=0, s=0, h=10000000000000;
	char a[1001];
	scanf("%s",a);
	int n=strlen(a);
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 'a')
		{
			m++;
		}
	}
	if (m > n - m)
	{
		m = n - m;
		g = 1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int k = i; k < i+m; k++)
		{

			if (g == 1 && a[k % n] == 'a')
			{
				f++;
			}
			if (g == 0 && a[k % n] == 'b')
			{
				d++;
			}
			
		}
		if (g == 1 && h > f)
		{
			h = f;
		}
		if (g == 0 && h > d)
		{
			h = d;
		}
		d = f = 0;
	}
	printf("%d", h);
	

}