#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
typedef tuple<pll, string, ll>pllsl;
ll n = 0, m = 0, k = 0;
vector<vector<char>>Map(101, vector<char>(101, '0'));
bool visited[101][101];
ll Forward[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
void bfs(ll y, ll x) {
    queue<pll>q;
    visited[y][x] = true;
    q.push({ y, x });
    while (!q.empty()) {
        pll temp = q.front();
        q.pop();
        visited[temp.first][temp.second] = true;
        for (int i = 0; i < 4; i++) {
            ll dy = temp.first + Forward[i][0];
            ll dx = temp.second + Forward[i][1];
            if (dy >= 0 && dy < n && dx >= 0 && dx < m && !visited[dy][dx] && Map[dy][dx] != '0') {
                visited[dy][dx] = true;
                q.push({ dy, dx });
            }
        }
    }
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
    while (1) {
        ll end = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && Map[i][j] != '0') {
                    bfs(i, j);
                    end++;
                }
            }
        }
        if (end == 1) {
            break;
        }
        vector<vector<char>>update(101, vector<char>(101, '0'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (Map[i][j] != '0') {
                    ll temp = Map[i][j] - '0';
                    for (int k = i - temp; k <= i + temp; k++) {
                        for (int u = j - temp; u <= j + temp; u++) {
                            if (k >= 0 && k < n && u >= 0 && u < m) {
                                update[k][u] = max(update[k][u], Map[i][j]);
                            }
                        }
                    }
                }
            }
        }
        Map = update;
        count++;
        memset(visited, false, sizeof(visited));
    }
    cout << count;
    return 0;
}