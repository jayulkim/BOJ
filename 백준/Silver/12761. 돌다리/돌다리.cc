#include <bits/stdc++.h>
using namespace std;
int a = 0, b = 0, n = 0, m = 0;
bool visited[100001];
void bfs() {
    queue<pair<int, int>>q;
    visited[n] = true;
    q.push({n, 0});
    while(!q.empty()) {
        pair<int, int>temp = q.front();
        q.pop();
        if (temp.first == m) {
            cout << temp.second;
            return;
        }
        if (temp.first - 1 >= 0 && !visited[temp.first - 1]) {
            q.push({temp.first - 1, temp.second + 1});
            visited[temp.first - 1] = true;
        }
        if (temp.first + 1 <= 100000 && !visited[temp.first + 1]) {
            q.push({temp.first + 1, temp.second + 1});
            visited[temp.first + 1] = true;
        }
        if (temp.first + a <= 100000 && !visited[temp.first + a]) {
            q.push({temp.first + a, temp.second + 1});
            visited[temp.first + a] = true;
        }
        if (temp.first + b <= 100000 && !visited[temp.first + b]) {
            q.push({temp.first + b, temp.second + 1});
            visited[temp.first + b] = true;
        }
        if (temp.first - a >= 0 && !visited[temp.first - a]) {
            q.push({temp.first - a, temp.second + 1});
            visited[temp.first - a] = true;
        }
        if (temp.first - b >= 0 && !visited[temp.first - b]) {
            q.push({temp.first - b, temp.second + 1});
            visited[temp.first - b] = true;
        }
        if (temp.first * a <= 100000 && !visited[temp.first * a]) {
            q.push({temp.first * a, temp.second + 1});
            visited[temp.first * a] = true;           
        }
        if (temp.first * b <= 100000 && !visited[temp.first * b]) {
            q.push({temp.first * b, temp.second + 1});
            visited[temp.first * b] = true;
        }
    }
}
int main(void) {
	ios::sync_with_stdio(false);	cin.tie(0);
	cin >> a >> b >> n >> m;
    bfs();
	return 0;
}