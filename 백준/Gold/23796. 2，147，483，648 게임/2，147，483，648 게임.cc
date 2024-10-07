#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Map[10][10];
void Sortmap(string command)
{
	if (command == "L")
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 1; j < 8; j++)
			{
				if (Map[i][j] != 0)
				{
					int x = j;
					while (x - 1 >= 0 && Map[i][x - 1] == 0)
					{
						x--;
					}
					swap(Map[i][x], Map[i][j]);
				}
			}
		}
	}
	else if (command == "R")
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 7; j >= 0; j--)
			{
				if (Map[i][j] != 0)
				{
					int x = j;
					while (x + 1 < 8 && Map[i][x + 1] == 0)
					{
						x++;
					}
					swap(Map[i][x], Map[i][j]);
				}
			}
		}
	}
	else if (command == "U")
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (Map[j][i] != 0)
				{
					int y = j;
					while (y - 1 >= 0 && Map[y - 1][i] == 0)
					{
						y--;
					}
					swap(Map[y][i], Map[j][i]);
				}
			}
		}
	}
	else if (command == "D")
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 7; j >= 0; j--)
			{
				if (Map[j][i] != 0)
				{
					int y = j;
					while (y + 1 < 8 && Map[y + 1][i] == 0)
					{
						y++;
					}
					swap(Map[y][i], Map[j][i]);
				}
			}
		}
	}
}
void solve(string command)
{
	Sortmap(command);
	if (command == "L")
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				while (Map[i][j] == Map[i][j + 1] && Map[i][j] != 0)
				{
					Map[i][j] += Map[i][j + 1];
					Map[i][j + 1] = 0;
				}
			}
		}
	}
	else if (command == "R")
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 7; j >= 1; j--)
			{
				while (Map[i][j] == Map[i][j - 1] && Map[i][j] != 0)
				{
					Map[i][j] += Map[i][j - 1];
					Map[i][j - 1] = 0;
				}
			}
		}
	}
	else if (command == "U")
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				while (Map[j][i] == Map[j + 1][i] && Map[j][i] != 0)
				{
					Map[j][i] += Map[j + 1][i];
					Map[j + 1][i] = 0;
				}
			}
		}
	}
	else if (command == "D")
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 7; j >= 1; j--)
			{
				while (Map[j][i] == Map[j - 1][i] && Map[j][i] != 0)
				{
					Map[j][i] += Map[j - 1][i];
					Map[j - 1][i] = 0;
				}
			}
		}
	}
	Sortmap(command);
}
int main(void)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> Map[i][j];
		}
	}
	string command = "";
	cin >> command;
	solve(command);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << Map[i][j] << ' ';
		}
		cout << '\n';
	}
}