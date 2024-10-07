#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<ll>s;
queue<pair<ll, ll>>q;
ll n = 0;
int m = 0, k = 0;
void bfs() {
	while (!q.empty()) {
		pair<ll, ll>temp = q.front();
		q.pop();
		cout << temp.second << '\n';
		k--;
		if (k == 0) {
			return;
		}
		if (temp.first - 1 >= 0 && s.find(temp.first - 1) == s.end()) {
			s.insert(temp.first - 1);
			q.push({ temp.first - 1, temp.second + 1 });
		}
		if (temp.first + 1 <= n && s.find(temp.first + 1) == s.end()) {
			s.insert(temp.first + 1);
			q.push({ temp.first + 1, temp.second + 1 });
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		ll num = 0;
		cin >> num;
		q.push({ num, 0 });
		s.insert(num);
	}
	bfs();
	return 0;
}