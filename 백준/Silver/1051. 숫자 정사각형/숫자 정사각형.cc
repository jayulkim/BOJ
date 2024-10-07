#include <bits/stdc++.h>
using namespace std;
string Map[51];
int rect(int y, int x)
{
	int Max = 0;
	int temp = min(y, x);
	for (int i = 0; i <= temp; i++)
	{
		if (Map[y - i][x - i] == Map[y][x] && Map[y - i][x] == Map[y][x] && Map[y][x - i] == Map[y][x])
		{
			Max = max(Max, (i + 1) * (i + 1));
		}
	}
	return Max;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0; 
	cin >> n >> m;
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> Map[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			result = max(result, rect(i, j));
		}
	}
	cout << result;
}