#include <bits/stdc++.h>
using namespace std;
int ary[1001];
int v[1001][6];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> v[i][j];
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				if (v[i][k] == v[j][k])
				{
					ary[i + 1]++;
					ary[j + 1]++;
					break;
				}
			}
		}
	}
	int Max = -1;
	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		if (Max < ary[i])
		{
			Max = ary[i];
			result = i;
		}
	}
	cout << result;
	return 0;
}