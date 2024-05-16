#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll addmod(ll x, ll y, ll num)
{
	x %= num;
	y %= num;
	if (num - y <= x)
	{
		return x - (num - y);
	}
	else
	{
		return x + y;
	}
}
ll mulmod(ll x, ll y, ll num)
{
	x %= num;
	y %= num;
	ll result = 0;
	while (y > 0)
	{
		if (y % 2 == 1)
		{
			result = addmod(result, x, num);
			result %= num;
		}
		x = addmod(x, x, num);
		x %= num;
		y /= 2;
	}
	return result;
}
ll powmod(ll x, ll y, ll num)
{
	x %= num;
	ll result = 1;
	while (y > 0)
	{
		if (y % 2 == 1)
		{
			result = mulmod(result, x, num);
			result %= num;
		}
		x = mulmod(x, x, num);
		x %= num;
		y /= 2;
	}
	return result;
}
int main(void)
{
	int n = 0;
	cin >> n;
	ll result = 0;
	for (int i = 0; i < n; i++)
	{
		ll down = 0, up = 0;
		cin >> down >> up;
		result = addmod(result, mulmod(up, powmod(down, 1000000005, 1000000007), 1000000007), 1000000007);
		result %= 1000000007;
	}
	cout << result % 1000000007;
}