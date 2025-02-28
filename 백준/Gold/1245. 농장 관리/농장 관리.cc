#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
typedef tuple<pll, string, ll>pllsl;
ll n = 0, m = 0, k = 0;
ll Map[101][101];
ll Forward[8][2] = { {-1, -1}, {-1, 0}, {0, -1}, {1, 0}, {0, 1}, {1, 1}, {1, -1}, {-1, 1} };
bool visited[101][101];
ll bfs(ll y, ll x, ll num) {
    visited[y][x] = true;
    queue<pll>q;
    q.push({ y, x });
    bool find = false;
    while (!q.empty()) {
        pll temp = q.front();
        q.pop();
        visited[temp.first][temp.second] = true;
        for (int i = 0; i < 8; i++) {
            ll dy = temp.first + Forward[i][0];
            ll dx = temp.second + Forward[i][1];
            if (dy >= 0 && dy < n && dx >= 0 && dx < m && !visited[dy][dx] && Map[dy][dx] == num) {
                visited[dy][dx] = true;
                q.push({ dy, dx });
            }
            if (dy >= 0 && dy < n && dx >= 0 && dx < m && Map[dy][dx] > num) {
                find = true;
            }
        }
    }
    if (!find) {
        return 1;
    }
    return 0;
}
int main(void) {
    ios::sync_with_stdio(false);             
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> Map[i][j];
        }
    }
    ll count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                count += bfs(i, j, Map[i][j]);
            }
        }
    }
    cout << count;
    return 0;
}