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
	cin >> n >> m;
	vector<string>v({ "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" });
	ll temp = 0;
	for (int i = 1; i < n; i++) {
		if (i == 2) {
			temp += 28;
		}
		else if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
			temp += 31;
		}
		else {
			temp += 30;
		}
	}
	temp += m;
	temp--;
	cout << v[temp % 7];
	return 0;
}