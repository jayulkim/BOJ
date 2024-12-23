#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
string str = "";
string result = "";
vector<ll>startidx(100001);
vector<ll>endidx(100001);
map<char, char>a;
map<char, char>b;
void dfs(ll start, ll end, bool mirrora, bool mirrorb) {
	if (!mirrora) {
		for (int i = start; i <= end; i++) {
			if (str[i] == '(') {
				if (!mirrorb) {
					dfs(i + 1, endidx[i] - 1, true, false);
				}
				else {
					dfs(i + 1, endidx[i] - 1, true, true);
				}
				i = endidx[i];
			}
			else if (str[i] == '[') {
				if (!mirrorb) {
					dfs(i + 1, endidx[i] - 1, false, true);
				}
				else {
					dfs(i + 1, endidx[i] - 1, false, false);
				}
				i = endidx[i];
			}
			else {
				if (!mirrorb) {
					result += str[i];
				}
				else {
					result += b[str[i]];
				}
			}
		}
	}
	else {
		for (int i = end; i >= start; i--) {
			if (str[i] == ')') {
				if (!mirrorb) {
					dfs(startidx[i] + 1, i - 1, false, false);
				}
				else {
					dfs(startidx[i] + 1, i - 1, false, true);
				}
				i = startidx[i];
			}
			else if (str[i] == ']') {
				if (!mirrorb) {
					dfs(startidx[i] + 1, i - 1, true, true);
				}
				else {
					dfs(startidx[i] + 1, i - 1, true, false);
				}
				i = startidx[i];
			}
			else {
				if (!mirrorb) {
					result += a[str[i]];
				}
				else {
					result += a[b[str[i]]];
				}
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	a['b'] = 'd';
	a['d'] = 'b';
	a['p'] = 'q';
	a['q'] = 'p';
	a['o'] = 'o';
	a['x'] = 'x';
	b['b'] = 'p';
	b['d'] = 'q';
	b['p'] = 'b';
	b['q'] = 'd';
	b['o'] = 'o';
	b['x'] = 'x';
	cin >> str;
	string temp = "";
	vector<ll>v;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(' || str[i] == '[') {
			v.push_back(i);
		}
		else if (str[i] == ')' || str[i] == ']') {
			ll temp = v.back();
			v.pop_back();
			startidx[i] = temp;
			endidx[temp] = i;
		}
	}
	dfs(0, str.length() - 1, false, false);
	cout << result;
	return 0;
}