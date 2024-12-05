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
	string str = "";
	cin >> str;
	vector<pair<char, ll>>v;
	ll Max = 0;
	ll count = 0;
	ll idx = -1;
	for (int i = 0; i < n; i++) {
		if (v.empty()) {
			v.push_back({ str[i], i });
			count = 0;
		}
		else {
			if (v.back().first == 'N' && str[i] == 'S') {
				count++;
				v.pop_back();
			}
			else {
				if (v.back().second != i - 1) {
					vector<pair<char, ll>>().swap(v);
				}
				v.push_back({ str[i], i });
				count = 0;
			}
		}
		Max = max(Max, count * 2);
	}
	count = 0;
	vector<pair<char, ll>>().swap(v);
	for (int i = 0; i < n; i++) {
		if (v.empty()) {
			v.push_back({ str[i], i });
			count = 0;
		}
		else {
			if (v.back().first == 'S' && str[i] == 'N') {
				count++;
				v.pop_back();
			}
			else {
				if (v.back().second != i - 1) {
					vector<pair<char, ll>>().swap(v);
				}
				v.push_back({ str[i], i });
				count = 0;
			}
		}
		Max = max(Max, count * 2);
	}
	cout << Max;
	return 0;
}