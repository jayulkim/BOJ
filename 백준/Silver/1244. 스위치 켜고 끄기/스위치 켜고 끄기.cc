#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<int>v(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	int m = 0;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int num1 = 0, num2 = 0;
		cin >> num1 >> num2;
		if (num1 == 1)
		{
			for (int j = num2; j <= n; j += num2)
			{
				if (v[j] == 0)
				{
					v[j] = 1;
				}
				else
				{
					v[j] = 0;
				}
			}
		}
		else
		{
			int start = num2;
			int end = num2;
			for (int j = 1; j <= n; j++)
			{
				if (j + num2 > n || num2 - j < 1)
				{
					break;
				}
				if (v[j + num2] == v[num2 - j])
				{
					start--;
					end++;
				}
				else
				{
					break;
				}
			}
			for (int j = start; j <= end; j++)
			{
				if (v[j] == 1)
				{
					v[j] = 0;
				}
				else
				{
					v[j] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << v[i] << ' ';
		if (i % 20 == 0)
		{
			cout << '\n';
		}
	}
	return 0;
}