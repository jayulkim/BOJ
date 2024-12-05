#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<ll>graph[501];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0;
	cin >> num;
	while (num--) {
		cin >> n;
		vector<ll>v;
		for (int i = 0; i < n; i++) {
			ll a = 0;
			cin >> a;
			v.push_back(a);
		}
		sort(v.begin(), v.end(), greater<ll>());
		ll result = 0;
		for (int i = 0; i < n; i++) {
			result += max((ll)0, v[i] - i);
		}
		cout << result << '\n';
	}
	return 0;
}