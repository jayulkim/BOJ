#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, char> llc;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	string str = "";
	vector<char>stack;
	cin >> str;
	ll count = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] == 'E') {
			stack.push_back(str[i]);
		}
		else {
			if (!stack.empty()) {
				count++;
			}
			while (!stack.empty()) {
				stack.pop_back();
			}
		}
	}
	cout << count;
	return 0;
}