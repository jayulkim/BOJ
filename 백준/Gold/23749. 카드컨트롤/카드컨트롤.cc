#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
map<string, ll>Map;
void bfs(string start) {
	Map[start]++;
	queue<pair<string, ll>>q;
	q.push({ start, 0 });
	while (!q.empty()) {
		pair<string, ll>temp = q.front();
		q.pop();
		Map[temp.first]++;
		ll a = 0, b = 0;
		for (int i = 0; i < 2 * n; i += 2) {
			if (temp.first[i] == 'O' && temp.first[i + 1] == 'X') {
				a++;
			}
			else if (temp.first[i] == 'X' && temp.first[i + 1] == 'O') {
				b++;
			}
		}
		if (a > b) {
			cout << temp.second;
			return;
		}
		for (int i = 1; i < 2 * n; i++) {
			string str = "";
			str += temp.first[i];
			for (int j = 0; j < 2 * n; j++) {
				if (i != j) {
					str += temp.first[j];
				}
			}
			if (!Map[str]) {
				Map[str]++;
				q.push({ str, temp.second + 1 });
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	string str = "";
	for (int i = 0; i < 2 * n; i++) {
		char c;
		cin >> c;
		str += c;
	}
	bfs(str);
	return 0;
}