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
	cin >> n >> m >> k;
	vector<ll>a(n + 1);
	vector<vector<ll>>p(m + 1);
	vector<vector<ll>>w(m + 1);
	vector<ll>b(m + 1);
	for (int i = 0; i < m; i++) {
		ll ci = 0;
		cin >> ci;
		for (int j = 0; j < ci; j++) {
			ll pci = 0;
			cin >> pci;
			p[i].push_back(--pci);
		}
		for (int j = 0; j < ci; j++) {
			ll wci = 0;
			cin >> wci;
			w[i].push_back(wci);
		}
		ll bi = 0;
		cin >> bi;
		b[i] = bi;
	}
	for (int i = 0; i < m; i++) {
		ll wi = 0;
		cin >> wi;
		w[m].push_back(wi);
	}
	ll bi = 0;
	cin >> bi;
	b[m] = bi;
	vector<ll>mul(n + 1, 0);
	ll add = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < p[i].size(); j++) {
			mul[p[i][j]] += w[i][j] * w[m][i];
		}
	}
	for (int i = 0; i < m; i++) {
		add += b[i] * w[m][i];
	}
	add += b[m];
	function<ll()> nu = [&]() -> ll {
		ll result = 0;
		for (int i = 0; i < n; i++) {
			result += mul[i] * a[i];
		}
		result += add;
		return result;
		};
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			ll ai = 0;
			cin >> ai;
			a[j] = ai;
		}
		cout << nu() << '\n';
	}
	return 0;
}