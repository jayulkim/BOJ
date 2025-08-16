#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<vector<ll>>Map(n + 1, vector<ll>(m + 1));
    vector<vector<ll>>sum(n + 1, vector<ll>(m + 1, 0));
    vector<vector<ll>>visited(n + 1, vector<ll>(m + 1, 0));
    vector<vector<ll>>forward = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> Map[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + Map[i][j];
        }
    }
    ll a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
    cin >> a >> b >> c >> d >> e >> f;
    queue<lll>q;
    q.push({ 1, c, d });
    while (!q.empty()) {
        auto [aa, bb, cc] = q.front();
        q.pop();
        visited[bb][cc] = aa;
        if (bb == e && cc == f) {
            cout << aa - 1;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            ll dy = bb + forward[i][0];
            ll dx = cc + forward[i][1];
            if (dy >= 1 && dy <= n && dx >= 1 && dx <= m && !visited[dy][dx] && dy + a - 1 <= n && dx + b - 1 <= m) {
                if (!(sum[dy + a - 1][dx + b - 1] - sum[dy + a - 1][dx - 1] - sum[dy - 1][dx + b - 1] + sum[dy - 1][dx - 1])) {
                    visited[dy][dx] = true;
                    q.push({ aa + 1, dy, dx });
                }
            }
        }
    }
    cout << -1;
    return 0; 
}