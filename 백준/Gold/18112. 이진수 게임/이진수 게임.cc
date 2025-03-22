#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
string a = "", b = "";
bool visited[1025];
ll getnum(string str) {
	ll result = 0;
	for (int i = str.length() - 1; i >= 0; i--) {
		result += pow(2, str.length() - 1 - i) * (str[i] - '0');
	}
	return result;
}
void bfs(string start, string end) {
	visited[getnum(start)] = true;
	queue<pll>q;
	ll e = getnum(end);
	q.push({ getnum(start), 0 });
	while (!q.empty()) {
		pll temp = q.front();
		q.pop();
		if (temp.first == e) {
			cout << temp.second;
			return;
		}
		visited[temp.first] = true;
		if (temp.first && !visited[temp.first - 1]) {
			visited[temp.first - 1] = true;
			q.push({ temp.first - 1, temp.second + 1 });
		}
		if (temp.first + 1 <= 1023 && !visited[temp.first + 1]) {
			visited[temp.first + 1] = true;
			q.push({ temp.first + 1, temp.second + 1 });
		}
		ll size = 0;
		ll t = temp.first;
		while (t > 0) {
			size++;
			t /= 2;
		}
		ll bit = 1;
		for (int i = 0; i < size - 1; i++) {
			if (!visited[(temp.first ^ (bit << i))]) {
				visited[(temp.first ^ (bit << i))] = true;
				q.push({ (temp.first ^ (bit << i)), temp.second + 1 });
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b;
	bfs(a, b);
	return 0;
}