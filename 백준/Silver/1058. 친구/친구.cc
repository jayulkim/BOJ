#include <bits/stdc++.h>
using namespace std;
char Map[51][51];
bool visited[51][51];
int main(void)
{
	int n = 0;
	cin >> n;
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> Map[i][j];
			if (Map[j][i] == 'Y')
			{
				Map[i][j] = 'Y';
			}
			if (Map[i][j] == 'Y')
			{
				Map[j][i] = 'Y';
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (Map[j][i] == 'Y')
			{
				Map[i][j] = 'Y';
			}
			if (Map[i][j] == 'Y')
			{
				Map[j][i] = 'Y';
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			if (Map[i][j] == 'Y')
			{
				count++;
			}
			else
			{
				for (int k = 0; k < n; k++)
				{
					if (Map[i][k] == 'Y' && Map[j][k] == 'Y')
					{
						count++;
						break;
					}
				}
			}
		}
		result = max(result, count);
	}
	if (result == 0)
	{
		cout << result;
	}
	else
	{
		cout << result - 1;
	}
	return 0;
}