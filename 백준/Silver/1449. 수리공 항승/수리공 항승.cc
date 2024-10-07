#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int idx = 0;
	int result = 0;
	while (idx < n)
	{
		int count = 1;
		for (int i = idx + 1; i < n; i++)
		{
			if (v[idx] + m > v[i])
			{
				count++;
			}
			else
			{
				break;
			}
		}
		idx += count;
		result++;
	}
	cout << result;
	return 0;
}