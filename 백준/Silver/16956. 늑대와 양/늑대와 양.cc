#include <bits/stdc++.h>
using namespace std;
char Map[501][501];
struct pos
{
	int y;
	int x;
};
int main(void)
{
	int r = 0, c = 0;
	cin >> r >> c;
	vector<pos>v;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> Map[i][j];
			if (Map[i][j] == 'W')
			{
				v.push_back({ i, j });
			}
		}
	}
	if (v.size() == 0)
	{
		cout << 1 << '\n';
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cout << Map[i][j];
			}
			cout << '\n';
		}
		return 0;
	}
	for (auto& i : v)
	{
		if (Map[i.y][i.x - 1] == 'S' && i.x - 1 >= 0)
		{
			cout << 0;
			return 0;
		}
		else if (Map[i.y][i.x - 1] != 'W' && i.x - 1 >= 0)
		{
			Map[i.y][i.x - 1] = 'D';
		}
		if (Map[i.y][i.x + 1] == 'S' && i.x + 1 < c)
		{
			cout << 0;
			return 0;
		}
		else if (Map[i.y][i.x + 1] != 'W' && i. x + 1 < c)
		{
			Map[i.y][i.x + 1] = 'D';
		}
		if (Map[i.y - 1][i.x] == 'S' && i.y - 1 >= 0)
		{
			cout << 0;
			return 0;
		}
		else if (Map[i.y - 1][i.x] != 'W' && i.y - 1 >= 0)
		{
			Map[i.y - 1][i.x] = 'D';
		}
		if (Map[i.y + 1][i.x] == 'S' && i.y + 1 < r)
		{
			cout << 0;
			return 0;
		}
		else if (Map[i.y + 1][i.x] != 'W' && i.y + 1 < r)
		{
			Map[i.y + 1][i.x] = 'D';
		}
	}
	cout << 1 << '\n';
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << Map[i][j];
		}
		cout << '\n';
	}
	return 0;
}