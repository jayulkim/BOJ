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
	ll a = 0, b = 0, c = 0, k = 0, l = 0;
	cin >> a >> b >> c >> k >> l;
	ll temp1 = powmod(a, powmod(b, c, 6), 7);
	ll temp2 = mulmod(powmod(b, c, 7), powmod(a, 5, 7), 7);
	if (addmod(k, temp1, 7) == l && addmod(k, temp2, 7) == l)
	{
		cout << 3;
	}
	else if (addmod(k, temp1, 7) == l && addmod(k, temp2, 7) != l)
	{
		cout << 1;
	}
	else if (addmod(k, temp1, 7) != l && addmod(k, temp2, 7) == l)
	{
		cout << 2;
	}
	else
	{
		cout << 0;
	}
	return 0;
}