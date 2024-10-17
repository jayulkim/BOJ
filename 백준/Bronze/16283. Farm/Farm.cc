#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	bool check = false;
	ll a = 0, b = 0, c = 0, d = 0;
	cin >> a >> b >> c >> d;
	pii ans;
	for (int i = 1; i <= 1000; ++i)
	{
		for (int j = 1; j <= 1000; ++j)
		{
			if (i + j > c)
			{
				break;
			}
			if (i + j == c && a * i + b * j == d)
			{
				if (check)
				{
					cout << -1;
					return 0;
				}
				ans = make_pair(i, j);
				check = true;
			}
		}
	}
	if (check)
	{
		cout << ans.first << ' ' << ans.second; 
	}
	else
	{
		cout << -1;
	}
	return 0;
}