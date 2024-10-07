#include <bits/stdc++.h>
using namespace std;
char Map[101][101];
bool visitedhigh[101][101];
bool visitedwidth[101][101];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> Map[i][j];
		}
	}
	int width = 0;
	int high = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int counthigh = 0;
			for (int k = i; k < n; k++)
			{
				if (Map[k][j] == '.' && visitedhigh[k][j] == false)
				{
					counthigh++;
					visitedhigh[k][j] = true;
				}
				else
				{
					break;
				}
			}
			if (counthigh >= 2)
			{
				high++;
			}
			int countwidth = 0;
			for (int k = j; k < n; k++)
			{
				if (Map[i][k] == '.' && visitedwidth[i][k] == false)
				{
					countwidth++;
					visitedwidth[i][k] = true;
				}
				else
				{
					break;
				}
			}
			if (countwidth >= 2)
			{
				width++;
			}
		}
	}
	cout << width << ' ' << high;
	return 0;
}