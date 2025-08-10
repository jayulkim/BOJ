#include <bits/stdc++.h>
using namespace std;
typedef int ll;
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
    vector<vector<ll>>Map(n + 1, vector<ll>(n + 1));
    vector<vector<ll>>visited(n + 1, vector<ll>(n + 1, false));
    priority_queue<llll, vector<llll>, greater<llll>>pq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> Map[i][j];
            if (Map[i][j]) {
                pq.push({ 0, Map[i][j], i, j });
            }
        }
    }
    vector<pll>Forward = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
    ll a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    while (!pq.empty()) {
        auto [d, e, f, g] = pq.top();
        pq.pop();
        visited[f][g] = e;
        if (d + 1 <= a) {
            for (int i = 0; i < 4; i++) {
                ll dy = f + Forward[i].first;
                ll dx = g + Forward[i].second;
                if (dy < n && dy >= 0 && dx >= 0 && dx < n && !visited[dy][dx]) {
                    visited[dy][dx] = e;
                    pq.push({ d + 1, e, dy, dx });
                }
            }
        }
    }
    cout << visited[b - 1][c - 1];
    return 0;
}