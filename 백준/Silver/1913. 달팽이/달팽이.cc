#include <bits/stdc++.h>
using namespace std;
int Map[1000][1000];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	int target = 0;
	cin >> n;
	cin >> target;
	int y = 0;
	int x = 0;
	if (n % 2 == 0)
	{
		Map[n / 2][n / 2 - 1] = 1;
		y = n / 2;
		x = n / 2 - 1;
	}
	else
	{
		Map[n / 2][n / 2] = 1;
		y = n / 2;
		x = n / 2;
	}
	int count = 2;
	int r = 1;
	while (count <= n * n)
	{
		Map[y - 1][x] = count;
		y--;
		count++;
		for (int i = 0; i < r; i++)
		{
			Map[y][x + 1] = count;
			count++;
			x++;
		}
		for (int i = 0; i < r + 1; i++)
		{
			Map[y + 1][x] = count;
			count++;
			y++;
		}
		for (int i = 0; i < r + 1; i++)
		{
			Map[y][x - 1] = count;
			count++;
			x--;
		}
		for (int i = 0; i < r + 1; i++)
		{
			Map[y - 1][x] = count;
			count++;
			y--;
		}
		r += 2;
	}
	int resultx = 0;
	int resulty = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (Map[i][j] == target)
			{
				resulty = i + 1;
				resultx = j + 1;
			}
			cout << Map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << resulty << ' ' << resultx;
	return 0;
}