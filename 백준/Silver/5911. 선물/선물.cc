#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
bool compare(const pll& a, const pll& b) {
	return a.first + a.second < b.first + b.second;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vector<pll>v;
	for (int i = 0; i < n; i++) {
		ll a = 0, b = 0;
		cin >> a >> b;
		v.push_back({ a, b });
	}
	ll Max = 0;
	for (int i = 0; i < n; i++) {
		ll sum = 0;
		vector<pll>temp;
		for (int j = 0; j < n; j++) {
			if (j == i) {
				temp.push_back({ v[j].first / 2, v[j].second });
			}
			else {
				temp.push_back({ v[j].first, v[j].second });
			}
		}
		sort(temp.begin(), temp.end(), compare);
		ll count = 0;
		for (int j = 0; j < n; j++) {
			sum += temp[j].first;
			sum += temp[j].second;
			if (sum > m) {
				break;
			}
			else {
				count++;
			}
		}
		Max = max(Max, count);
	}
	cout << Max;
	return 0;
}