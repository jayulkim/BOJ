#include <bits/stdc++.h>
using namespace std;
int Forward[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
int Map[21][21];
bool visited[21][21];
int n = 0, m = 0, Min = 500;
queue<pair<pair<int, int>, int>>q;
int result = 0, Find = 0;
int bfs() {
    while (!q.empty()) {
        pair<pair<int, int>, int>temp = q.front();
        q.pop();
        if (Map[temp.first.first][temp.first.second] == '1') {
            result++;
        }
        if (result == Find) {
            result = 0;
            queue<pair<pair<int, int>, int>>().swap(q);
            return temp.second;
        }
        visited[temp.first.first][temp.first.second] = true;
        for (int i = 0; i < 4; i++) {
            int dy = temp.first.first + Forward[i][0];
            int dx = temp.first.second + Forward[i][1];
            if (dy >= 0 && dy < n && dx >= 0 && dx < m && !visited[dy][dx]) {
                visited[dy][dx] = true;
                q.push({ {dy, dx}, temp.second + 1 });
            }
        }
    }
}
vector<pair<int, int>>zero;
void solve() {
    for (int i = 0; i < zero.size() - 1; i++) {
        for (int j = i + 1; j < zero.size(); j++) {
            q.push({ {zero[i].first, zero[i].second}, 0 });
            q.push({ {zero[j].first, zero[j].second}, 0 });
            Min = min(Min, bfs());
            memset(visited, false, sizeof(visited));
        }
    }
    cout << Min;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string str = "";
        cin >> str;
        for (int j = 0; j < m; j++) {
            Map[i][j] = str[j];
            if (Map[i][j] == '1') {
                Find++;
            }
            else {
                zero.push_back({ i, j });
            }
        }
    }
    solve();
    return 0;
}