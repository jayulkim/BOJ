#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
{
	ll n = 0, l = 0;
	cin >> n >> l;
	while (l * (l - 1) / 2 <= n)
	{
		if ((n - (l * (l - 1) / 2)) % l == 0 && l <= 100)
		{
			ll result = (n - (l * (l - 1) / 2)) / l;
			for (int i = 0; i < l; i++)
			{
				cout << result << ' ';
				result++;
			}
			return 0;
		}
		l++;
	}
	cout << -1;
	return 0;
}