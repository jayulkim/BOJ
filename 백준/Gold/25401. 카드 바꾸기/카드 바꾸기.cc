#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, char> plc;
typedef pair<string, ll> psl;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll, ll, ll, ll, ll, ll>llllllll;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<ll>v;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		v.push_back(num);
	}
	ll Min = n;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if ((v[i] - v[j]) % (j - i) == 0) {
				ll temp = (v[i] - v[j]) / (j - i);
				ll a = v[i] - i * temp;
				ll count = 0;
				for (int k = 0; k < n; k++) {
					if (a + temp * k != v[k]) {
						count++;
					}
				}
				Min = min(Min, count);
			}
			if ((v[j] - v[i]) % (j - i) == 0) {
				ll temp = (v[j] - v[i]) / (j - i);
				ll a = v[i] - i * temp;
				ll count = 0;
				for (int k = 0; k < n; k++) {
					if (a + temp * k != v[k]) {
						count++;
					}
				}
				Min = min(Min, count);
			}
		}
	}
	cout << Min;
	return 0;
}