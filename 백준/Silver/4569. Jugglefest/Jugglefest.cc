#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<char, ll> pll;
typedef pair<ld, ld> pld;
ll n = 0, m = 0, k = 0;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		cin >> n;
		if (!n) {
			break;
		}
		vector<pll>v;
		vector<ll>vv;
		vector<ll>vvv;
		string result = "";
		for (int i = 0; i < n; i++) {
			cin >> m;
			vv.push_back(m);
		}
		ll cnt = 'A';
		for (int i = 0; i < 20; i++) {
			vvv.push_back(vv[i % vv.size()]);
		}
		bool find = false;
		while (result.length() < 20) {
			vector<pll>temp;
			ll idx = -1;
			for (int i = 0; i < v.size(); i++) {
				if (v[i].second == result.length()) {
					temp.push_back(v[i]);
					idx = i;
				}
			}
			if (temp.size() > 1) {
				find = true;
				cout << "CRASH" << '\n';
				break;
			}
			else if (!temp.size()) {
				result += cnt;
				v.push_back({ cnt, vvv[result.length() - 1] + result.length() - 1 });
				cnt++;
			}
			else if (temp.size() == 1) {
				result += temp[0].first;
				v[idx].second += vvv[result.length() - 1];
			}
		}
		if (!find) {
			cout << result << '\n';
		}
	}
    return 0;
}