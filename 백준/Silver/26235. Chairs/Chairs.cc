#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
ll n = 0, m = 0, k = 0;
vector<pll>chair;
bool visited[101][101];
string result = "";
string bfs(ll starty, ll startx, ll endy, ll endx) {
	queue<pair<pll, string>>q;
	visited[starty][startx] = true;
	q.push({ { starty, startx }, "" });
	while (!q.empty()) {
		pair<pll, string> temp = q.front();
		q.pop();
		if (temp.first.first == endy && temp.first.second == endx) {
			return temp.second;
		}
		if (temp.first.first + 1 < n && !visited[temp.first.first + 1][temp.first.second]) {
			visited[temp.first.first + 1][temp.first.second] = true;
			q.push({ {temp.first.first + 1, temp.first.second}, temp.second + 'D'});
		}
		if (temp.first.second + 1 < m && !visited[temp.first.first][temp.first.second + 1]) {
			visited[temp.first.first][temp.first.second] = true;
			q.push({ {temp.first.first, temp.first.second + 1}, temp.second + 'R' });
		}
	}
	memset(visited, false, sizeof(visited));
	return "-";
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	if (!k) {
		cout << bfs(0, 0, n - 1, m - 1);
		return 0;
	}
	for (int i = 0; i < k; i++) {
		ll a = 0, b = 0;
		cin >> a >> b;
		chair.push_back({ a - 1, b - 1 });
	}
	sort(chair.begin(), chair.end());
	string temp = bfs(0, 0, chair[0].first, chair[0].second);
	if (temp != "-") {
		if (temp != "") {
			result += temp;
		}
		for (int i = 1; i < k; i++) {
			string temp = bfs(chair[i - 1].first, chair[i - 1].second, chair[i].first, chair[i].second);
			if (temp != "-") {
				if (temp != "") {
					result += temp;
				}
			}
			else {
				cout << "Impossible";
				return 0;
			}
		}
	}
	else {
		cout << "Impossible";
		return 0;
	}
	temp = bfs(chair.back().first, chair.back().second, n - 1, m - 1);
	if (temp != "-") {
		if (temp != "") {
			result += temp;
		}
		if (result.length() == n + m - 2) {
			cout << result;
		}
		else {
			cout << "Impossible";
			return 0;
		}
	}
	else {
		cout << "Impossible";
		return 0;
	}
	return 0;
}