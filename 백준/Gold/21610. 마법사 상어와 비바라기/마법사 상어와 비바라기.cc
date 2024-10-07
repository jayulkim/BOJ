#include <bits/stdc++.h>
using namespace std;
int Map[51][51];
bool visited[51][51];
int main(void)
{
	int n = 0, m = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> Map[i][j];
		}
	}
	vector<pair<int, int>>v;
	v.push_back(make_pair(n - 1, 0));
	v.push_back(make_pair(n - 1, 1));
	v.push_back(make_pair(n - 2, 0));
	v.push_back(make_pair(n - 2, 1));
	for (int i = 0; i < m; i++)
	{
		int forward = 0, distence = 0;
		cin >> forward >> distence;
		if (forward == 1)
		{
			for (int j = 0; j < distence; j++)
			{
				for (auto& k : v)
				{
					k.second = (k.second - 1 + n) % n;
				}				
			}
		}
		else if (forward == 2)
		{
			for (int j = 0; j < distence; j++)
			{
				for (auto& k : v)
				{
					k.first = (k.first - 1 + n) % n;
					k.second = (k.second - 1 + n) % n;
				}
			}
		}
		else if (forward == 3)
		{
			for (int j = 0; j < distence; j++)
			{
				for (auto& k : v)
				{
					k.first = (k.first - 1 + n) % n;
				}
			}
		}
		else if (forward == 4)
		{
			for (int j = 0; j < distence; j++)
			{
				for (auto& k : v)
				{
					k.second = (k.second + 1 + n) % n;
					k.first = (k.first - 1 + n) % n;
				}
			}
		}
		else if (forward == 5)
		{
			for (int j = 0; j < distence; j++)
			{
				for (auto& k : v)
				{
					k.second = (k.second + 1 + n) % n;
				}
			}
		}
		else if (forward == 6)
		{
			for (int j = 0; j < distence; j++)
			{
				for (auto& k : v)
				{
					k.first = (k.first + 1 + n) % n;
					k.second = (k.second + 1 + n) % n;
				}
			}
		}
		else if (forward == 7)
		{
			for (int j = 0; j < distence; j++)
			{
				for (auto& k : v)
				{
					k.first = (k.first + 1 + n) % n;
				}
			}
		}
		else if (forward == 8)
		{
			for (int j = 0; j < distence; j++)
			{
				for (auto& k : v)
				{
					k.first = (k.first + 1 + n) % n;
					k.second = (k.second - 1 + n) % n;
				}
			}
		}
		for (auto& j : v)
		{
			Map[j.first][j.second]++;
		}
		for (auto& j : v)
		{
			if (j.first - 1 >= 0 && j.second - 1 >= 0 && Map[j.first - 1][j.second - 1] != 0)
			{
				Map[j.first][j.second]++;
			}
			if (j.first - 1 >= 0 && j.second + 1 < n && Map[j.first - 1][j.second + 1] != 0)
			{
				Map[j.first][j.second]++;
			}
			if (j.first + 1 < n && j.second - 1 >= 0 && Map[j.first + 1][j.second - 1] != 0)
			{
				Map[j.first][j.second]++;
			}
			if (j.first + 1 < n && j.second < n && Map[j.first + 1][j.second + 1] != 0)
			{
				Map[j.first][j.second]++;
			}
		}
		for (auto& j : v)
		{
			visited[j.first][j.second] = true;
		}
		v.clear();
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (Map[j][k] >= 2 && !visited[j][k])
				{
					v.push_back(make_pair(j, k));
					Map[j][k] -= 2;
				}
			}
		}
		memset(visited, false, sizeof(visited));
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sum += Map[i][j];
		}
	}
	cout << sum;
	return 0;
}