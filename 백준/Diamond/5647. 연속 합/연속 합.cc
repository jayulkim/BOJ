#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll ary[12] = { 2,3,5,7,11,13,17,19,23,29,31,37 };
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
	for (int i = 0; i < 12; i++)
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
	return (mulmod(x, x, num) % num + c) % num;
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
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<ll>v;
	while (1)
	{
		ll q = 0;
		ll result = 1;
		cin >> q;
		if (q == 0)
		{
			break;
		}
		if (q % 2 == 0)
		{
			while (q > 1)
			{
				ll temp = pollardrho(q);
				v.push_back(temp);
				q /= temp;
			}
			sort(v.begin(), v.end());
			v.push_back(0);
			int idx = 0;
			for (int i = 0; i < v.size(); i++)
			{
				if (v[i] != 2)
				{
					idx = i;
					break;
				}
			}
			ll count = 0;
			for (int i = idx; i < v.size() - 1; i++)
			{
				if (v[i] != v[i + 1])
				{
					count++;
					count *= 2;
					count++;
					result *= count;
					count = 0;
				}
				else
				{
					count++;
				}
			}
			result *= 2;
			cout << result << '\n';
		}
		else
		{
			while (q > 1)
			{
				ll temp = pollardrho(q);
				v.push_back(temp);
				q /= temp;
			}
			sort(v.begin(), v.end());
			v.push_back(0);
			ll count = 0;
			for (int i = 0; i < v.size() - 1; i++)
			{
				if (v[i] != v[i + 1])
				{
					count++;
					count *= 2;
					count++;
					result *= count;
					count = 0;
				}
				else
				{
					count++;
				}
			}
			result *= 2;
			cout << result << '\n';
		}
		vector<ll>().swap(v);
	}
	return 0;
}