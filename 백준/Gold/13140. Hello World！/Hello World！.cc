#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
bool visited[11];
vector<ll>result;
bool Find = false;
void dfs() {
	if (Find) {
		return;
	}
	if (result.size() == 7) {
		if (result[0] != 0 && result[4] != 0) {
			string a = "", b = "";
			for (int i = 0; i < 2; i++) {
				a += (result[i] + '0');
			}
			a += (result[2] + '0');
			a += (result[2] + '0');
			a += (result[3] + '0');
			b += (result[4] + '0');
			b += (result[3] + '0');
			b += (result[5] + '0');
			b += (result[2] + '0');
			b += (result[6] + '0');
			if (stoll(a) + stoll(b) == n) {
				cout << "  " << a << '\n';
				cout << "+ " << b << '\n';
				cout << "-------" << '\n';
				if (n >= 100000) {
					cout << " ";
				}
				else {
					cout << "  ";
				}
				cout << n;
				Find = true;
				return;
			}
		}
		else {
			return;
		}
	}
	for (int i = 0; i < 10; i++) {
		if (!visited[i]) {
			result.push_back(i);
			visited[i] = true;
			dfs();
			visited[i] = false;
			result.pop_back();
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	dfs();
	if (!Find) {
		cout << "No Answer";
	}
	return 0;
}