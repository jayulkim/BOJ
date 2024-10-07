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
	ary(int num1, ll num2)
	{
		n = num1;
		b = num2;
	}
	ll** arymul(ll** x, ll** y, int n, ll num)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				x[i][j] %= num;
				y[i][j] %= num;
			}
		}
		ll** result = (ll**)malloc(sizeof(ll) * n);
		for (int i = 0; i < n; i++)
		{
			result[i] = (ll*)malloc(sizeof(ll) * n);
		}	
		for (int i = 0; i < n; i++)
		{
			for (int k = 0; k < n; k++)
			{
				ll sum = 0;
				for (int j = 0; j < n; j++)
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
	ll** arypow(ll** x, ll b, int n, ll num)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				x[i][j] %= num;
			}
		}
		ll** result = (ll**)malloc(sizeof(ll) * n);
		for (int i = 0; i < n; i++)
		{
			result[i] = (ll*)malloc(sizeof(ll) * n);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				result[i][j] = x[i][j] % num;
			}
		}
		b -= 1;
		while (b > 0)
		{
			if (b % 2 == 1)
			{
				result = arymul(result, x, n, num);
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < n; j++)
					{
						result[i][j] %= num;
					}
				}
			}
			x = arymul(x, x, n, num);
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					x[i][j] %= num;
				}
			}
			b /= 2;
		}
		return result;
	}
private:
	int n;
	ll b;
};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	ll b = 0;
	cin >> n >> b;
	ary solve = ary(n, b);
	ll** result = (ll**)malloc(sizeof(ll) * n);
	for (int i = 0; i < n; i++)
	{
		result[i] = (ll*)malloc(sizeof(ll) * n);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> result[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << solve.arypow(result, b, n, 1000LL)[i][j] << ' ';
		}
		cout << '\n';
	}
}