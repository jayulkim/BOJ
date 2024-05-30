#include <bits/stdc++.h>
using namespace std;
int ary[1001][133];
int main(void)
{
	int n = 0, m = 0;
	cin >> n >> m;
	vector<string>v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	string result = "";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ary[i][v[j][i]]++;
		}
		int idx = 0;
		int Max = 0;
		for (int j = 0; j < 133; j++)
		{
			if (Max < ary[i][j])
			{
				Max = ary[i][j];
				idx = j;
			}
		}
		result += (char)idx;
	}
	int count = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (v[j][i] != result[i])
			{
				count++;
			}
		}
	}
	cout << result << '\n' << count;
	return 0;
}