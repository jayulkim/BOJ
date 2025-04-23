#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll> lll;
typedef tuple<pll, string, ll> pllsl;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	function<ll(ll, ll)> dfs = [&](ll start, ll end) -> ll {
		if (end == start) {
			return start;
		}
		if (end - start == 1) {
			cout << "? " << start << ' ' << 0 << ' ' << end << ' ' << 0 << endl;
			char ch = '\0';
			cin >> ch;
			if (ch == '<') {
				return start;
			}
			else if (ch == '>') {
				return end;
			}
		}
		if (end - start == 2) {
			cout << "? " << start << ' ' << 0 << ' ' << start + 1 << ' ' << 0 << endl;
			char ch = '\0';
			cin >> ch;
			if (ch == '<') {
				return start;
			}
			else if (ch == '>') {
				return start + 1;
			}
			else {
				return end;
			}
		}
		cout << "?";
		for (int i = start; i <= start + (end - start) / 3; i++) {
			cout << ' ' << i;
		}
		cout << ' ' << 0;
		for (int i = start + (end - start) / 3 + 1; i <= start + (end - start) / 3 + 1 + (end - start) / 3; i++) {
			cout << ' ' << i;
		}
		cout << ' ' << 0;
		cout << endl;
		char ch = '\0';
		cin >> ch;
		if (ch == '=') {
			return dfs(start + (end - start) / 3 + 2 + (end - start) / 3, end);
		}
		else if (ch == '<') {
			return dfs(start, start + (end - start) / 3);
		}
		else if (ch == '>') {
			return dfs(start + (end - start) / 3 + 1, start + (end - start) / 3 + 1 + (end - start) / 3);
		}
		};
	ll result = dfs(1, n);
	cout << "! " << result << endl;
	return 0;
}