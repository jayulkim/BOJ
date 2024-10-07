#include <iostream>
using namespace std;
class GCD
{
public:
	GCD(unsigned long long int num1, unsigned long long int num2)
	{
		x = num1;
		y = num2;
	}
	unsigned long long int gcd()
	{
		unsigned long long int temp = x % y;
		while (temp > 0)
		{
			x = y;
			y = temp;
			temp = x % y;
		}
		return y;
	}
	unsigned long long int gcd(unsigned long long int i)
	{
		unsigned long long int gcdxy = gcd();
		unsigned long long int temp = i % gcdxy;
		while (temp > 0)
		{
			i = gcdxy;
			gcdxy = temp;
			temp = i % gcdxy;
		}
		return gcdxy;
	}
	unsigned long long int gcd(unsigned long long int num, unsigned long long int i)
	{
		unsigned long long int temp = num % i;
		while (temp > 0)
		{
			num = i;
			i = temp;
			temp = num % i;
		}
		return i;
	}
private:
	unsigned long long int x;
	unsigned long long int y;
};
class LCM
{
public:
	LCM(unsigned long long int num1, unsigned long long int num2)
	{
		g = new GCD(num1, num2);
		mulxy = num1 * num2;
	}
	unsigned long long int lcm()
	{
		return mulxy / g->gcd();
	}
	unsigned long long int lcm(unsigned long long int i)
	{
		return lcm() * i / g->gcd(lcm(), i);
	}
private:
	unsigned long long int mulxy;
	GCD* g;
};
class Solve
{
public:
	Solve(unsigned long long int num1, unsigned long long int num2, unsigned long long int num3)
	{
		a = num1;
		b = num2;
		c = num3;
		l = new LCM(a, b);
	}
	void solve()
	{
		unsigned long long int num1 = l->lcm();
		if (c % num1 != 0)
		{
			cout << -1;
		}
		else
		{
			for (unsigned long long int i = c / num1; i <= 1000000000000; i += c / num1)
			{
				if (l->lcm(i) == c)
				{
					cout << i;
					break;
				}
			}
		}
	}
private:
	unsigned long long int a;
	unsigned long long int b;
	unsigned long long int c;
	LCM* l;
};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	unsigned long long int num1 = 0;
	unsigned long long int num2 = 0;
	unsigned long long int num3 = 0;
	cin >> num1 >> num2 >> num3;
	Solve s = Solve(num1, num2, num3);
	s.solve();
}