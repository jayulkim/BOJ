#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
char Map[101][101];
struct pos
{
	int y;
	int x;
};
bool compare(const pos& num1, const pos& num2)
{
	if (num1.y == num2.y)
	{
		return num1.x < num2.x;
	}
	return num1.y < num2.y;
}
char result[101][101];
int Find[101][101];
int Forward[10][2] = { {0, 0}, {1, -1}, {1, 0}, {1, 1}, {0, -1}, {0, 0}, {0, 1}, {-1, -1}, {-1, 0}, {-1, 1} };
int main(void)
{
	int n = 0, m = 0;
	cin >> n >> m;
	int playery = 0, playerx = 0;
	vector<pos>crazy;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> Map[i][j];
			if (Map[i][j] == 'I')
			{
				playery = i;
				playerx = j;
			}
			else if (Map[i][j] == 'R')
			{
				crazy.push_back({ i, j });
			}
		}
	}
	string str = "";
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		int temp = str[i] - 48;
		playery += Forward[temp][0];
		playerx += Forward[temp][1];
		for (auto& j : crazy)
		{
			if (j.y == playery && j.x == playerx)
			{
				cout << "kraj" << ' ' << i + 1;
				return 0;
			}
		}
		for (auto& j : crazy)
		{
			int movey = 0;
			int movex = 0;
			int Min = 10001;
			for (int k = 1; k <= 9; k++)
			{
				if (j.y + Forward[k][0] >= 0 && j.y + Forward[k][0] < n && j.x + Forward[k][1] >= 0 && j.x + Forward[k][1] < m && Min > abs(playery - (j.y + Forward[k][0])) + abs(playerx - (j.x + Forward[k][1])))
				{
					Min = abs(playery - (j.y + Forward[k][0])) + abs(playerx - (j.x + Forward[k][1]));
					movey = j.y + Forward[k][0];
					movex = j.x + Forward[k][1];
				}
			}
			j.y = movey;
			j.x = movex;
			if (j.y == playery && j.x == playerx)
			{
				cout << "kraj" << ' ' << i + 1;
				return 0;
			}
			Find[j.y][j.x]++;
		}
		crazy.clear();
		for (int j = 0; j <= 100; j++)
		{
			for (int k = 0; k <= 100; k++)
			{
				if (Find[j][k] == 1)
				{
					crazy.push_back({ j, k });
				}
			}
		}
		memset(Find, 0, sizeof(Find));
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			result[i][j] = '.';
		}
	}
	for (auto& i : crazy)
	{
		result[i.y][i.x] = 'R';
	}
	result[playery][playerx] = 'I';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << result[i][j];
		}
		cout << '\n';
	}
}