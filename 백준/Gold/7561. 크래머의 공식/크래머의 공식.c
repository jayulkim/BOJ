#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

long long int ary[5][5];

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				scanf("%lld", &ary[j][k]);
			}
		}
		long long int det1 = ary[0][3] * (ary[1][1] * ary[2][2] - ary[1][2] * ary[2][1]) - ary[0][1] * (ary[1][3] * ary[2][2] - ary[1][2] * ary[2][3]) + ary[0][2] * (ary[1][3] * ary[2][1] - ary[1][1] * ary[2][3]);
		long long int det2 = ary[0][0] * (ary[1][3] * ary[2][2] - ary[1][2] * ary[2][3]) - ary[0][3] * (ary[1][0] * ary[2][2] - ary[1][2] * ary[2][0]) + ary[0][2] * (ary[1][0] * ary[2][3] - ary[1][3] * ary[2][0]);
		long long int det3 = ary[0][0] * (ary[1][1] * ary[2][3] - ary[1][3] * ary[2][1]) - ary[0][1] * (ary[1][0] * ary[2][3] - ary[1][3] * ary[2][0]) + ary[0][3] * (ary[1][0] * ary[2][1] - ary[1][1] * ary[2][0]);
		long long int det = ary[0][0] * (ary[1][1] * ary[2][2] - ary[1][2] * ary[2][1]) - ary[0][1] * (ary[1][0] * ary[2][2] - ary[1][2] * ary[2][0]) + ary[0][2] * (ary[1][0] * ary[2][1] - ary[1][1] * ary[2][0]);
		printf("%lld %lld %lld %lld\n", det1, det2, det3, det);

		if (det == 0)
		{
			printf("No unique solution\n");
			printf("\n");
		}
		else
		{
			long double x1 = (long double)det1 / (long double)det;
			long double x2 = (long double)det2 / (long double)det;
			long double x3 = (long double)det3 / (long double)det;
			if (x1 * 10000 > -5 && x1 * 10000 < 5)
			{
				x1 = 0.000;
			}
			if (x2 * 10000 > -5 && x2 * 10000 < 5)
			{
				x2 = 0.000;
			}
			if (x3 * 10000 > -5 && x3 * 10000 < 5)
			{
				x3 = 0.000;
			}
			printf("Unique solution: %.3LF %.3LF %.3Lf\n", x1, x2, x3);
			printf("\n");
		}



	}

}
