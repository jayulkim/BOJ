#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, char> plc;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
bool visited[10000001];
ll result = 0;
string s = "";
string str = "";
bool v[8];
vector<bool>vv(10000001, false);
void dfs(ll n) {
	if (s.length() == n) {
		if (!vv[stoll(s)] && !visited[stoll(s)]) {
			result++;
			vv[stoll(s)] = true;
		}
		return;
	}
	for (int i = 0; i < str.length(); i++) {
		if (!v[i]) {
			s.push_back(str[i]);
			v[i] = true;
			dfs(n);
			v[i] = false;
			s.pop_back();
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	visited[1] = true;
	visited[0] = true;
	for (int i = 2; i * i <= 10000000; i++) {
		if (!visited[i]) {
			for (int j = i * i; j <= 10000000; j += i) {
				visited[j] = true;
			}
		}
	}
	ll num = 0;
	cin >> num;
	while (num--) {
		cin >> str;
		for (int i = 1; i <= str.length(); i++) {
			dfs(i);
			memset(v, false, sizeof(v));
		}
		cout << result << '\n';
		result = 0;
		vector<bool>(10000001, false).swap(vv);
	}
	return 0;
}