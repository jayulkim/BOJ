#include <bits/stdc++.h>
using namespace std;

class ps
{
public:
	ps(int num1, int num2)
	{
		n = num1;
		m = num2;
		result = 0;
	}
	void input()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);
		for (int i = 0; i < n; i++)
		{
			cin >> map[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> target[i];
		}
	}
	void swap(int starty, int startx)
	{
		for (int i = starty; i < starty + 3; i++)
		{
			for (int j = startx; j < startx + 3; j++)
			{
				if (map[i][j] == '0')
				{
					map[i][j] = '1';
				}
				else if (map[i][j] == '1')
				{
					map[i][j] = '0';
				}
			}
		}
	}
	void solve()
	{
		input();
		if (n < 3 || m < 3)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (map[i][j] != target[i][j])
					{
						cout << -1;
						return;
					}
				}
			}
			cout << 0;
			return;
		}	
		for (int i = 0; i <= n - 3; i++)
		{
			for (int j = 0; j <= m - 3; j++)
			{
				if (map[i][j] != target[i][j])
				{
					swap(i, j);
					result++;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] != target[i][j])
				{
					cout << -1;
					return;
				}
			}
		}
		cout << result;
	}
private:
	int result;
	int n;
	int m;
	char map[51][51];
	char target[51][51];
};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num1 = 0, num2 = 0;
	cin >> num1 >> num2;
	ps p = ps(num1, num2);
	p.solve();
}