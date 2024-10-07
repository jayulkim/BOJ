#include <bits/stdc++.h>
using namespace std;
int ary[4];
bool dp[10001];
int main(void)
{
	for (int i = 0; i < 4; i++)
	{
		cin >> ary[i];
	}
	int temp = min(min(min(1000 * ary[0] + 100 * ary[1] + 10 * ary[2] + ary[3], 1000 * ary[1] + 100 * ary[2] + 10 * ary[3] + ary[0]), 1000 * ary[2] + 100 * ary[3] + 10 * ary[0] + ary[1]), 1000 * ary[3] + 100 * ary[0] + 10 * ary[1] + ary[2]);
	int start = 1111;
	int count = 1;
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			for (int k = 1; k <= 9; k++)
			{
				for (int n = 1; n <= 9; n++)
				{
					ary[0] = i;
					ary[1] = j;
					ary[2] = k;
					ary[3] = n;
					dp[min(min(min(1000 * ary[0] + 100 * ary[1] + 10 * ary[2] + ary[3], 1000 * ary[1] + 100 * ary[2] + 10 * ary[3] + ary[0]), 1000 * ary[2] + 100 * ary[3] + 10 * ary[0] + ary[1]), 1000 * ary[3] + 100 * ary[0] + 10 * ary[1] + ary[2])] = true;
				}
			}
		}
	}
	while (start < temp)
	{
		if (dp[start] == true)
		{
			count++;
		}
		start++;
	}
	cout << count;
}