#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
bool visited[1000001];
ll parent[1000001];
char ary[1000001];
bool Find = false;
string result = "";
void getparent(int x) {
	if (x == 1) {
		result += '1';
		return;
	}
	result += ary[x];
	getparent(parent[x]);
}
void bfs(ll x) {
	int idx = 1;
	visited[1] = true;
	parent[1] = 1;
	queue<ll>q;
	q.push(1);
	while (!q.empty()) {
		ll temp = q.front();
		q.pop();
		if (temp == 0) {
			Find = true;
			getparent(0);
			return;
		}
		visited[temp] = true;
		if ((temp * 10) % x >= 0 && (temp * 10) % x < 1000000 && !visited[(temp * 10) % x]) {
			visited[(temp * 10) % x] = true;
			parent[(temp * 10) % x] = temp;
			ary[(temp * 10) % x] = '0';
			q.push((temp * 10) % x);
		}
		if ((temp* 10 + 1) % x >= 0 && (temp * 10 + 1) % x < 1000000 && !visited[(temp * 10 + 1) % x]) {
			visited[(temp * 10 + 1) % x] = true;
			parent[(temp * 10 + 1) % x] = temp;
			ary[(temp * 10 + 1) % x] = '1';
			q.push((temp * 10 + 1) % x);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	cin >> num;
	while (num--) {
		ll n = 0;
		cin >> n;
		if (n == 1) {
			cout << 1 << '\n';
		}
		else {
			bfs(n);
			if (Find) {
				reverse(result.begin(), result.end());
				cout << result << '\n';
			}
			else {
				cout << "BRAK" << '\n';
			}
		}
		memset(visited, false, sizeof(visited));
		memset(ary, 0, sizeof(ary));
		memset(parent, 0, sizeof(parent));
		result = "";
	}
	return 0;
}