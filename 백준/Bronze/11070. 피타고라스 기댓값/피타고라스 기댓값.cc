#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int  T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, m = 0;
		cin >> n >> m;
		vector<pll>v(n + 1);
		for (int i = 0; i < m; ++i)
		{
			ll a = 0, b = 0, c = 0, d = 0;
			cin >> a >> b >> c >> d;
			v[a].first += c; v[b].first += d;
			v[a].second += d; v[b].second += c;
		}
		ll maxi = LLONG_MIN, mini = LLONG_MAX;
		for (int i = 1; i <= n; ++i)
		{
			ll a = v[i].first;
			ll b = v[i].second;
			if (a * a + b * b == 0)
			{
				maxi = max(0LL, maxi);
				mini = min(0LL, mini);
				continue;
			}
			ll pivot = (a * a * 1000LL) / ((a * a) + (b * b));
			maxi = max(pivot, maxi);
			mini = min(pivot, mini);
		}
		cout << maxi << '\n' << mini << '\n';
	}
	return 0;
}