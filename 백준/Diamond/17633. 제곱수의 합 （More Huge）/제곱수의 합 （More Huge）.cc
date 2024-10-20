#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ary[12] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };

long long int mod(long long int x, long long int y, long long int num)
{
    long long int result = 0;
    x %= num;
    y %= num;
    while (y > 0)
    {
        if (y % 2 == 1)
        {
            result += x;
            result %= num;
        }
        x *= 2;
        x %= num;
        y /= 2;
    }
    return result;
}

long long int gcd(long long int num1, long long int num2)
{
    long long int temp = num1 % num2;
    while (temp != 0)
    {
        num1 = num2;
        num2 = temp;
        temp = num1 % num2;
    }
    return num2;
}

long long int Pow(long long int prime, long long int d, long long int num)
{
    if (d == 0)
    {
        return 1LL;
    }
    long long int count = (Pow(prime, d / 2, num) % num);
    count %= num;
    if (d % 2 == 0)
    {
        return mod(count % num, count % num, num) % num;
    }
    else
    {
        return mod(mod((prime % num), (count % num), num), (count % num), num) % num;
    }
}

int millerlabin(long long int prime, long long int num)
{
    if (num < 2)
    {
        return 1;
    }
    if (num == 2)
    {
        return 0;
    }
    if (num % prime == 0)
    {
        return 0;
    }
    long long int num1 = num - 1;
    while (1)
    {
        long long int temp = Pow(prime, num1, num) % num;
        if (temp == num - 1)
        {
            return 0;
        }
        else
        {
            if (num1 % 2 == 0)
            {
                num1 /= 2;
            }
            else
            {
                if (temp == 1 || temp == num - 1)
                {
                    return 0;
                }
                else
                {
                    return 1;
                }
            }
        }
    }
}

int isprime(long long int num)
{
    for (int i = 0; i < 12; i++)
    {
        if (millerlabin(ary[i], num) == 1)
        {
            return 1;
        }
    }
    return 0;
}

long long int Random(long long int x, long long int c, long long int num)
{
    return (mod(x % num, x % num, num) + c % num) % num;
}

long long int pollardrho(long long int num)
{
    if (num % 2 == 0)
    {
        return 2;
    }
    if (isprime(num) == 0)
    {
        return num;
    }
    long long int x = (rand() % (num - 2)) + 1;
    long long int c = (rand() % 3) * 2 - 1;
    long long int y = x;
    long long int d = 1;
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
    if (isprime(gcd(d, num)) == 0)
    {
        return gcd(d, num);
    }
    else
    {
        return pollardrho(gcd(d, num));
    }
}
map<ll, ll>Map;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0;
	cin >> n;
	ll result = n;
	while (n > 1) {
		ll temp = pollardrho(n);
		Map[temp]++;
		n /= temp;
	}
	bool find = false;
	for (auto i = Map.begin(); i != Map.end(); i++) {
		if (i->second % 2) {
			find = true;
			break;
		}
	}
	if (!find) {
		cout << 1;
		return 0;
	}
	find = false;
	for (auto i = Map.begin(); i != Map.end(); i++) {
		if (i->first % 4 == 3) {
			if (i->second % 2) {
				find = true;
				break;
			}
		}
	}
	if (!find) {
		cout << 2;
		return 0;
	}
	while (result % 4 == 0) {
		result /= 4;
	}
	if (result % 8 == 7) {
		cout << 4;
		return 0;
	}
	cout << 3;
	return 0;
}