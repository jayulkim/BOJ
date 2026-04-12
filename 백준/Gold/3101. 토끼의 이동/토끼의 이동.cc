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
	cin >> n >> m;
	string str = "";
	cin >> str;
	ll count = 1, num = 1;
	ll result = 1;
	ll s = 1, e = 1;
	for (auto& i : str) {
		if (i == 'D') {
			if (count < n) {
				s = e + 1;
				e += count + 1;
				count++;
				num++;
			}
			else {
				s = e + 1;
				e += 2 * n - 1 - count;
				count++;
			}
		}
		else if (i == 'U') {
			if (count <= n) {
				e = s - 1;
				s -= count - 1;
				count--;
				num--;
			}
			else {
				e = s - 1;
				s -= (2 * n + 1 - count);
				count--;
			}
		}
		else if (i == 'R') {
			if (count < n) {
				s = e + 1;
				e += count + 1;
				count++;
			}
			else {
				s = e + 1;
				e += 2 * n - 1 - count;
				count++;
				num--;
			}
		}
		else if (i == 'L') {
			if (count <= n) {
				e = s - 1;
				s -= count - 1;
				count--;
			}
			else {
				e = s - 1;
				s -= (2 * n + 1 - count);
				count--;
				num++;
			}
		}
		if (count % 2) {
			result += e - num + 1;
		}
		else {
			result += s + num - 1;
		}
	}
	cout << result;
	return 0;
}