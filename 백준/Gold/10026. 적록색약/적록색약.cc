#include <bits/stdc++.h>
using namespace std;
bool visited[101][101];
char Map[101][101];
void dfsR(int y, int x, int n)
{
	visited[y][x] = true;
	if (y - 1 >= 0 && Map[y - 1][x] == 'R' && visited[y - 1][x] == false)
	{
		dfsR(y - 1, x, n);
	}
	if (y + 1 < n && Map[y + 1][x] == 'R' && visited[y + 1][x] == false)
	{
		dfsR(y + 1, x, n);
	}
	if (x - 1 >= 0 && Map[y][x - 1] == 'R' && visited[y][x - 1] == false)
	{
		dfsR(y, x - 1, n);
	}
	if (x + 1 < n && Map[y][x + 1] == 'R' && visited[y][x + 1] == false)
	{
		dfsR(y, x + 1, n);
	}
}
void dfsG(int y, int x, int n)
{
	visited[y][x] = true;
	if (y - 1 >= 0 && Map[y - 1][x] == 'G' && visited[y - 1][x] == false)
	{
		dfsG(y - 1, x, n);
	}
	if (y + 1 < n && Map[y + 1][x] == 'G' && visited[y + 1][x] == false)
	{
		dfsG(y + 1, x, n);
	}
	if (x - 1 >= 0 && Map[y][x - 1] == 'G' && visited[y][x - 1] == false)
	{
		dfsG(y, x - 1, n);
	}
	if (x + 1 < n && Map[y][x + 1] == 'G' && visited[y][x + 1] == false)
	{
		dfsG(y, x + 1, n);
	}
}
void dfsB(int y, int x, int n)
{
	visited[y][x] = true;
	if (y - 1 >= 0 && Map[y - 1][x] == 'B' && visited[y - 1][x] == false)
	{
		dfsB(y - 1, x, n);
	}
	if (y + 1 < n && Map[y + 1][x] == 'B' && visited[y + 1][x] == false)
	{
		dfsB(y + 1, x, n);
	}
	if (x - 1 >= 0 && Map[y][x - 1] == 'B' && visited[y][x - 1] == false)
	{
		dfsB(y, x - 1, n);
	}
	if (x + 1 < n && Map[y][x + 1] == 'B' && visited[y][x + 1] == false)
	{
		dfsB(y, x + 1, n);
	}
}
int main(void)
{
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> Map[i][j];
		}
	}
	int normal = 0, rgb = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == false && Map[i][j] == 'R')
			{
				normal++;
				dfsR(i, j, n);
			}
			if (visited[i][j] == false && Map[i][j] == 'G')
			{
				normal++;
				dfsG(i, j, n);
			}
			if (visited[i][j] == false && Map[i][j] == 'B')
			{
				normal++;
				dfsB(i, j, n);
			}
		}
	}
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (Map[i][j] == 'G')
			{
				Map[i][j] = 'R';
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == false && Map[i][j] == 'R')
			{
				rgb++;
				dfsR(i, j, n);
			}
			if (visited[i][j] == false && Map[i][j] == 'B')
			{
				rgb++;
				dfsB(i, j, n);
			}
		}
	}
	cout << normal << ' ' << rgb;
	return 0;
}