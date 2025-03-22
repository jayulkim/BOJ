#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	queue<ll>q;
	ll Max = 0;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		if (q.empty()) {
			q.push(num);
			Max = max(Max, (ll)q.size());
		}
		else {
			while (!q.empty() && num < q.size() + 1) {
				q.pop();
			}
			q.push(num);
			Max = max(Max, (ll)q.size());
		}
	}
	cout << Max;
	return 0;
}