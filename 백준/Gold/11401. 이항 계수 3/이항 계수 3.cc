#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll powmod(ll x, ll y, ll num)
{
	x %= num;
	ll result = 1;
	while (y > 0)
	{
		if (y % 2 == 1)
		{
			result *= x;
			result %= num;
		}
		x *= x;
		x %= num;
		y /= 2;
	}
	return result;
}
int main(void)
{
	ll n = 0, k = 0;
	cin >> n >> k;
	ll up = 1;
	ll down = 1;
	ll result = 1;
	if (k == 0 || k == n)
	{
		cout << 1;
		return 0;
	}
	if (k > n / 2)
	{
		k = n - k;
	}
	if (k == 1)
	{
		cout << n;
		return 0;
	}
	while (k >= 1)
	{
		up *= n--;
		up %= 1000000007;
		down *= k--;
		down %= 1000000007;
	}
	cout << (up % 1000000007) * powmod(down, 1000000005, 1000000007) % 1000000007;
	return 0;
}