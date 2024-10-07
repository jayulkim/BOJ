#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string, ll>Map;
map<string, ll>wMap;
map<string, ll>dMap;
bool day[11][7];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0;
	cin >> num;
	while (num--) {
		ll temp = 0;
		cin >> temp;
		vector<ll>v;
		for (int i = 0; i < 12; i++) {
			ll n = 0;
			cin >> n;
			v.push_back(n);
		}
		ll count = 0;
		for (int j = 0; j < 11; j++) {
			for (int i = 1; i < 11 - j; i++) {
				ll a = v[i - 1], b = v[i + j + 1];
				bool find = false;
				for (int k = i; k <= i + j; k++) {
					if (v[k] <= a || v[k] <= b) {
						find = true;
						break;
					}
				}
				if (!find) {
					count++;
				}
			}
		}
		cout << temp << ' ' << count << '\n';
	}
	return 0;
}