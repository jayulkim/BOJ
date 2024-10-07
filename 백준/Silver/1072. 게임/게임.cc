#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll x = 0, y = 0;
	ll z = 0;
	cin >> x >> y;
	z = y * 100 / x;
	ll start = 0;
	ll end = 1000000000000;
	ll mid = 0;
	if (z >= 99)
	{
		cout << -1;
		return 0;
	}
	while (start < end - 1)
	{
		mid = (start + end) / 2;
		if ((y + mid) * 100 / (x + mid) <= z)
		{
			start = mid;
		}
		else
		{
			end = mid;
		}
	}
	start++;
	if ((y + mid) * 100 / (x + mid) == z)
	{
		mid = (start + end) / 2;
	}
	cout << mid;
	return 0;
}