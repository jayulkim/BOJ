#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
typedef tuple<pll, string, ll>pllsl;
ll n = 0, m = 0, k = 0;
char Map[51][51];
bool visited[51][51];
ll Forward[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
ll bfs(ll y, ll x) {
    visited[y][x] = true;
    queue<pair<pll, ll>>q;
    q.push({ { y, x }, 0 });
    ll Max = 0;
    while (!q.empty()) {
        pair<pll, ll> temp = q.front();
        q.pop();
        visited[temp.first.first][temp.first.second] = true;
        Max = max(Max, temp.second);
        for (int i = 0; i < 4; i++) {
            ll dy = temp.first.first + Forward[i][0];
            ll dx = temp.first.second + Forward[i][1];
            if (dy >= 0 && dy < n && dx >= 0 && dx < m && !visited[dy][dx] && Map[dy][dx] == 'L') {
                visited[dy][dx] = true;
                q.push({ { dy, dx }, temp.second + 1 });
            }
        }
    }
    return Max;
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
    ll Max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (Map[i][j] == 'L') {
                Max = max(Max, bfs(i, j));
                memset(visited, false, sizeof(visited));
            }
        }
    }
    cout << Max;
    return 0;
}