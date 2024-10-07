#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
bool visited[200005];
int n = 0, m = 0;
void dijkstra(int start) {
	pq.push({ 0, start });
	while (!pq.empty()) {
		pair<int, int>temp = pq.top();
		visited[temp.second] = true;
		pq.pop();
		if (temp.second == m) {
			cout << temp.first;
			return;
		}
		if (temp.second * 2 <= 200004 && !visited[temp.second * 2]) {
			pq.push({ temp.first, temp.second * 2 });
			visited[temp.second * 2] = true;
		}
		if (temp.second - 1 >= 0 && !visited[temp.second - 1]) {
			pq.push({ temp.first + 1, temp.second - 1 });
			visited[temp.second - 1] = true;
		}
		if (temp.second + 1 <= 200004 && !visited[temp.second + 1]) {
			pq.push({ temp.first + 1, temp.second + 1 });
			visited[temp.second + 1] = true;
		}	
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	dijkstra(n);
	return 0;
}