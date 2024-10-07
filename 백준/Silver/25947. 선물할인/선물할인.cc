#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	ll n, b, a;
	cin >> n >> b >> a;
	vector<ll> v(n);
	for (auto& i : v)
		cin >> i;
	sort(v.begin(), v.end());

	ll sum = 0, idx = 0, ans = 0;
	for (ll i = 0; i < a; i++)
	{
		sum += v[i] / 2;
		if (sum <= b)
			ans = max(ans, i + 1);
	}
	for (ll i = a; i < n; i++)
	{
		sum -= v[i - a] / 2;
		sum += v[i - a];
		sum += v[i] / 2;
		if (sum <= b)
			ans = max(ans, i + 1);
	}
	cout << ans << '\n';
	return 0;
}