#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
{
	int n = 0, m = 0;
	cin >> n >> m;
	ll sum = 0;
	for (int i = 0; i < n; i++)
	{
		ll num = 0;
		cin >> num;
		sum += num;
	}
	for (int i = 0; i < m; i++)
	{
		ll num = 0;
		cin >> num;
		if (num != 0)
		{
			sum *= num;
		}
	}
	cout << sum;
}