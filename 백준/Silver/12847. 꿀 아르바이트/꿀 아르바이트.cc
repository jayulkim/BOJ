#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<ll>v;
	ll sum = 0, result = 0;
	int n = 0, m = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		ll num = 0;
		cin >> num;
		v.push_back(num);
	}
	for (int i = 0; i < m; i++)
	{
		sum += v.at(i);
	}
	result = sum;
	for (int i = m; i < n; i++)
	{
		sum -= v[i - m];
		sum += v[i];
		result = max(result, sum);
	}
	cout << result;
}