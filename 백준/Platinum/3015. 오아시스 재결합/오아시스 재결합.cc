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
	map<ll, ll>Map;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		v.push_back(num);
	}
	ll result = 0;
	vector<ll>stack;
	for (int i = 0; i < n; i++) {
		if (!stack.empty() && stack.back() > v[i]) {
			result++;
		}
		else {
			bool find = false;
			if (!stack.empty() && stack.back() < v[i]) {
				while (!stack.empty() && stack.back() < v[i]) {
					result += Map[stack.back()];
					Map[stack.back()] = 0;
					stack.pop_back();
				}
				if (!stack.empty() && stack[0] > v[i]) {
					result++;
					find = true;
				}
			}
			if (!stack.empty() && stack.back() == v[i]) {
				if (!stack.empty() && stack[0] > v[i] && !find) {
					result++;
				}
				result += Map[stack.back()];
				while (!stack.empty() && stack.back() == v[i]) {
					stack.pop_back();
				}
			}
		}
		stack.push_back(v[i]);
		Map[v[i]]++;
	}
	cout << result;
	return 0;
}