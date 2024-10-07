#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int result = 0;
	for (int i = n - 1; i >= 1; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (v[i] <= v[j])
			{
				result += (v[j] - v[i] + 1);
				v[j] -= (v[j] - v[i] + 1);
			}
		}
	}
	cout << result;
}