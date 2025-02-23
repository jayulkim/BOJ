#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
typedef tuple<pll, string, ll>pllsl;
ll n = 0, m = 0, k = 0;
char Map[1001][1001];
vector<vector<ll>>visited(1001, vector<ll>(1001, LLONG_MAX));
vector<vector<ll>>v(1001, vector<ll>(1001, LLONG_MAX));
ll Forward[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
void bfs(ll y, ll x) {
    queue<pair<pll, ll>>q;
    q.push({ {y, x}, 0 });
    visited[y][x] = 0;
    while (!q.empty()) {
        pair<pll, ll> temp = q.front();
        q.pop();
        visited[temp.first.first][temp.first.second] = temp.second;
        for (int i = 0; i < 4; i++) {
            ll dy = temp.first.first + Forward[i][0];
            ll dx = temp.first.second + Forward[i][1];
            if (dy >= 0 && dy < n && dx >= 0 && dx < m && visited[dy][dx] > temp.second + 1 && Map[dy][dx] != '#') {
                visited[dy][dx] = temp.second + 1;
                q.push({ {dy, dx}, temp.second + 1 });
            }
        }
    }
}
void bfsbfs(ll y, ll x) {
    queue<pair<pll, ll>>q;
    q.push({ {y, x}, 0 });
    v[y][x] = 0;
    while (!q.empty()) {
        pair<pll, ll> temp = q.front();
        q.pop();
        v[temp.first.first][temp.first.second] = temp.second;
        for (int i = 0; i < 4; i++) {
            ll dy = temp.first.first + Forward[i][0];
            ll dx = temp.first.second + Forward[i][1];
            if (dy >= 0 && dy < n && dx >= 0 && dx < m && v[dy][dx] > temp.second + 1 && Map[dy][dx] != '#' && temp.second + 1 < visited[dy][dx]) {
                v[dy][dx] = temp.second + 1;
                q.push({ {dy, dx}, temp.second + 1 });
            }
        }
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    ll y = 0, x = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> Map[i][j];
            if (Map[i][j] == 'J') {
                y = i;
                x = j;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (Map[i][j] == 'F') {
                bfs(i, j);
            }
        }
    }
    bfsbfs(y, x);
    ll Min = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((!i || !j || j == m - 1 || i == n - 1) && (Map[i][j] == '.' || Map[i][j] == 'J')) {
                Min = min(Min, v[i][j]);
            }
        }
    }
    if (Min == LLONG_MAX) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << Min + 1;
    return 0;
}