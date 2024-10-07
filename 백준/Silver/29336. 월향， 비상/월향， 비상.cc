#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct info
{
	ll day;
	ll sum;
};
int main(void)
{
	int n = 0, m = 0;
	cin >> n >> m;
	vector<ll>v(n);
	vector<info>c(m);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> c[i].day >> c[i].sum;
	}
	sort(v.begin(), v.end());
	ll temp = 0;
	ll result = 0;
	int idx = n - 1;
	for (int i = 0; i < m; i++)
	{
		if (i == 0)
		{
			temp += c[0].day;
		}
		else
		{
			temp += (c[i].day - c[i - 1].day);
		}
		while (result < c[i].sum)
		{
			if (idx == -1)
			{
				cout << -1;
				return 0;
			}
			result += (v[idx] + temp);
			idx--;	
		}
	}
	for (int i = idx; i >= 0; i--)
	{
		result += (temp + v[i]);
	}
	cout << result;
	return 0;
}