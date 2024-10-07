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
	}
	void swap(int endy, int endx)
	{
		for (int i = 0; i <= endy; i++)
		{
			for (int j = 0; j <= endx; j++)
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
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = m - 1; j >= 0; j--)
			{
				if (map[i][j] != '0')
				{
					swap(i, j);
					result++;
				}
			}
		}
		cout << result;
	}
private:
	int result;
	int n;
	int m;
	char map[101][101];
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