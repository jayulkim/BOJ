#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class antioverflow
{
public:
	static ll addmod(ll x, ll y, ll num)
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
	static ll mulmod(ll x, ll y, ll num)
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
};
class ary
{
public:
	ary(ll num1)
	{
		n = num1;
	}
	ll** arymul(ll** x, ll** y, ll num)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				x[i][j] %= num;
				y[i][j] %= num;
			}
		}
		ll** result = (ll**)malloc(sizeof(ll) * 2);
		for (int i = 0; i < 2; i++)
		{
			result[i] = (ll*)malloc(sizeof(ll) * 2);
		}	
		for (int i = 0; i < 2; i++)
		{
			for (int k = 0; k < 2; k++)
			{
				ll sum = 0;
				for (int j = 0; j < 2; j++)
				{
					sum = antioverflow::addmod(sum, antioverflow::mulmod(x[i][j], y[j][k], num), num);
					sum %= num;
				}
				result[i][k] = sum;
				result[i][k] %= num;
			}
		}
		return result;
	}
	ll** arypow(ll** x, ll num)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				x[i][j] %= num;
			}
		}
		ll** result = (ll**)malloc(sizeof(ll) * 2);
		for (int i = 0; i < 2; i++)
		{
			result[i] = (ll*)malloc(sizeof(ll) * 2);
		}
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				result[i][j] = x[i][j] % num;
			}
		}
		n -= 1;
		while (n > 0)
		{
			if (n % 2 == 1)
			{
				result = arymul(result, x, num);
				for (int i = 0; i < 2; i++)
				{
					for (int j = 0; j < 2; j++)
					{
						result[i][j] %= num;
					}
				}
			}
			x = arymul(x, x, num);
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					x[i][j] %= num;
				}
			}
			n /= 2;
		}
		return result;
	}
private:
	ll n;
};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		ll n = 0, m = 0;
		cin >> n >> m;
		ary solve = ary(m - 1);
		ll** result1 = (ll**)malloc(sizeof(ll) * 2);
		for (int i = 0; i < 2; i++)
		{
			result1[i] = (ll*)malloc(sizeof(ll) * 2);
		}
		result1[0][0] = 1;
		result1[0][1] = 1;
		result1[1][0] = 1;
		result1[1][1] = 0;
		cout << n << ' ' << (solve.arypow(result1, 1000000000)[0][0]) % 1000000000 << '\n';
	}
}
