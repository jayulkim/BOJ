#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool visited[10001];
bool ary[10001];
bool Find = false;
void bfs(int start, int end) {
	visited[start] = true;
	queue<pair<int, int>>q;
	q.push({ start, 0 });
	while (!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();
		visited[temp.first] = true;
		if (temp.first == end) {
			cout << temp.second << '\n';
			Find = true;
			return;
		}
		for (int i = 0; i < 4; i++) {
			string str = to_string(temp.first);
			for (int j = 0; j <= 9; j++) {
				str[i] = (char)(j + 48);
				if (stoi(str) >= 1000 && stoi(str) <= 9999 && !visited[stoi(str)] && !ary[stoi(str)]) {
					visited[stoi(str)] = true;
					q.push({ stoi(str), temp.second + 1 });
				}
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 2; i * i <= 10000; i++) {
		if (!ary[i]) {
			for (int j = i * i; j <= 10000; j += i) {
				ary[j] = true;
			}
		}
	}
	int num = 0;
	cin >> num;
	while (num--) {
		int n = 0, m = 0;
		cin >> n >> m;
		bfs(n, m);
		if (!Find) {
			cout << "Impossible" << '\n';
		}
		memset(visited, false, sizeof(visited));
		Find = false;
	}
	return 0;
}