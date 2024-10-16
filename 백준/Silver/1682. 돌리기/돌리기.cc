#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string, ll>Map;
string str = "";
void bfs() {
	Map["12345678"]++;
	queue<pair<string, ll>>q;
	q.push({ "12345678", 0 });
	while (!q.empty()) {
		pair<string, ll> temp = q.front();
		q.pop();
		if (temp.first == str) {
			cout << temp.second;
			return;
		}
		Map[temp.first]++;
		string a = temp.first;
		swap(a[3], a[4]);
		swap(a[2], a[5]);
		swap(a[1], a[6]);
		swap(a[0], a[7]);
		if (!Map[a]) {
			q.push({ a, temp.second + 1 });
			Map[a]++;
		}
		string b = temp.first;
		swap(b[0], b[3]);
		swap(b[1], b[3]);
		swap(b[2], b[3]);
		swap(b[4], b[7]);
		swap(b[4], b[5]);
		swap(b[5], b[6]);
		if (!Map[b]) {
			q.push({ b, temp.second + 1 });
			Map[b]++;
		}
		string c = temp.first;
		swap(c[1], c[6]);
		swap(c[1], c[5]);
		swap(c[1], c[2]);
		if (!Map[c]) {
			q.push({ c, temp.second + 1 });
			Map[c]++;
		}
		string d = temp.first;
		swap(d[0], d[4]);
		if (!Map[d]) {
			q.push({ d, temp.second + 1 });
			Map[d]++;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 8; i++) {
		char c;
		cin >> c;
		str += c;
	}
	bfs();
	return 0;
}