#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	map<ll, ll>Map;
	vector<pll>v;
	for (int i = 0; i < n; i++) {
		ll a = 0, b = 0;
		cin >> a >> b;
		v.push_back({ a, b });
		Map[a]++;
		Map[b + 1]--;
	}
	ll Max = 0;
	ll temp = 0;
	for (auto& i : Map) {
		temp += i.second;
		Max = max(Max, temp);
	}
	temp = 0;
	vector<ll>result;
	bool find = false;
	ll a = 0, b = 0;
	for (auto& i : Map) {
		temp += i.second;
		if (temp == Max) {
			find = true;
			a = i.first;
		}
		else if (find) {
			b = i.first - 1;
			break;
		}
	}
	cout << Max << '\n';
	for (int i = 0; i < n; i++) {
		if (v[i].first > b || v[i].second < a) {
			continue;
		}
		else {
			cout << i + 1 << ' ';
		}
	}
	return 0;
}