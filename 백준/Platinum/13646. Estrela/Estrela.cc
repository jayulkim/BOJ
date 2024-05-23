#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ary[3] = { 2,7,61 };
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
bool millerlabin(ll a, ll num)
{
	if (num == 1)
	{
		return false;
	}
	if (num == 2)
	{
		return true;
	}
	if (a == num)
	{
		return true;
	}
	ll num1 = num - 1;
	while (1)
	{
		ll temp = powmod(a, num1, num) % num;
		if (temp == num - 1)
		{
			return true;
		}
		else
		{
			if (num1 % 2 == 0)
			{
				num1 /= 2;
			}
			else
			{
				if (temp == num - 1 || temp % num == 1)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}
}
bool isprime(ll num)
{
	for (int i = 0; i < 3; i++)
	{
		if (millerlabin(ary[i], num) == false)
		{
			return false;
		}
	}
	return true;
}
ll gcd(ll num1, ll num2)
{
	ll temp = num1 % num2;
	while (temp > 0)
	{
		num1 = num2;
		num2 = temp;
		temp = num1 % num2;
	}
	return num2;
}
ll Random(ll x, ll c, ll num)
{
	return ((x % num) * (x % num) % num + c) % num;
}
ll pollardrho(ll num)
{
	if (num % 2 == 0)
	{
		return 2;
	}
	if (isprime(num) == true)
	{
		return num;
	}
	ll x = (rand() % (num - 2)) + 1;
	ll y = x;
	ll c = (rand() % 3) * 2 - 1;
	ll d = 1;
	while (gcd(d, num) == 1)
	{
		x = Random(x, c, num) % num;
		y = Random(y, c, num) % num;
		y = Random(y, c, num) % num;
		d = llabs(x - y);
		if (gcd(d, num) == num)
		{
			return pollardrho(gcd(d, num));
		}
	}
	if (isprime(gcd(d, num)) == true)
	{
		return gcd(d, num);
	}
	else
	{
		return pollardrho(gcd(d, num));
	}
}
vector<ll>v;
ll phi(ll num)
{
	ll result = 1;
	while (num > 1)
	{
		ll temp = pollardrho(num);
		v.push_back(temp);
		num /= temp;
	}
	sort(v.begin(), v.end());
	v.push_back(0);
	for (int i = 0; i < v.size() - 1; i++)
	{
		if (v[i] != v[i + 1])
		{
			result *= (v[i] - 1);
		}
		else
		{
			result *= v[i];
		}
	}
	result /= 2;
	vector<ll>().swap(v);
	return result;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0;
	while (cin >> n)
	{
		cout << phi(n) << '\n';
	}
	return 0;
}