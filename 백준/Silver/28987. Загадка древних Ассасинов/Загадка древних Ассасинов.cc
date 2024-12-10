#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<ll>v;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str = "";
	cin >> str;
	ll sum = 0;
	for (auto& i : str) {
		v.push_back(i - '0');
		sum += (i - '0');
	}
	sort(v.begin(), v.end(), greater<ll>());
	ll temp = sum % 3;
	if (!temp) {
		for (auto& i : v) {
			cout << i;
		}
		return 0;
	}
	bool find = false;
	for (int i = v.size() - 1; i >= 0; i--) {
		if (v[i] % 3 == temp) {
			v.erase(v.begin() + i);
			find = true;
			break;
		}
	}
	if (find) {
		for (auto& i : v) {
			cout << i;
		}
		return 0;
	}
	ll count = 0;
	for (int i = v.size() - 1; i >= 0; i--) {
		if (count == 2) {
			break;
		}
		if (v[i] % 3 == 3 - temp) {
			v.erase(v.begin() + i);
			count++;
		}
	}
	for (auto& i : v) {
		cout << i;
	}
	return 0;
}