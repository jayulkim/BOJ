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
    vector<vector<ll>>Map(n + 1, vector<ll>(n + 1));
    vector<vector<vector<ll>>>dist(n + 1, vector<vector<ll>>(n + 1, vector<ll>(3, LLONG_MAX)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> Map[i][j];
        }
    }
    priority_queue<llll, vector<llll>, greater<llll>>pq;
    vector<vector<ll>>forward = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    pq.push({ 0, 0, 0, 0 });
    dist[0][0][0] = 0;
    while (!pq.empty()) {
        auto [a, b, c, d] = pq.top();
        pq.pop();
        if (dist[b][c][d] >= a) {
            for (int i = 0; i < 4; i++) {
                ll dy = b + forward[i][0];
                ll dx = c + forward[i][1];
                if (dy >= 0 && dy < n && dx >= 0 && dx < n) {
                    if (d == 2) {
                        if (dist[dy][dx][0] > dist[b][c][d] + m + Map[dy][dx]) {
                            dist[dy][dx][0] = dist[b][c][d] + m + Map[dy][dx];
                            pq.push({ dist[dy][dx][0], dy, dx, 0 });
                        }
                    }
                    else {
                        if (dist[dy][dx][d + 1] > dist[b][c][d] + m) {
                            dist[dy][dx][d + 1] = dist[b][c][d] + m;
                            pq.push({ dist[dy][dx][d + 1], dy, dx, d + 1 });
                        }
                    }
                }
            }
        }
    }
    cout << min({ dist[n - 1][n - 1][0], dist[n - 1][n - 1][1], dist[n - 1][n - 1][2] });
    return 0; 
}