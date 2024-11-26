#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0;
	cin >> num;
	while (num--) {
		cin >> n;
		if (n == 1) {
			string str = "";
			cin >> str;
			ll result = 0;
			vector<ll>v;
			string temp = "";
			for (auto& i : str) {
				if (i == '.') {
					v.push_back(stoull(temp));
					temp = "";
				}
				else {
					temp += i;
				}
			}
			if (temp != "") {
				v.push_back(stoull(temp));
			}
			reverse(v.begin(), v.end());
			ll count = 1;
			for (auto& i : v) {
				result += (count * i);
				count *= 256;
			}
			cout << result << '\n';
		}
		else {
			cin >> m;
			vector<ll>v;
			while (m > 0) {
				v.push_back(m % 256);
				m /= 256;
			}
			while (v.size() < 8) {
				v.push_back(0);
			}
			for (int i = v.size() - 1; i >= 0; i--) {
				if (i) {
					cout << v[i] << '.';
				}
				else {
					cout << v[i] << '\n';
				}
			}
			
		}
	}
	return 0;
}