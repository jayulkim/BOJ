//폰 코딩
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll Map[201][201];
bool visited[201][201][31];
ll horse[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
ll monkey[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void bfs(ll y, ll x) {
    visited[y][x][0] = true;
    queue<llll>q;
    q.push({y, x, 0, 0});
    while (!q.empty()) {
        auto [a, b, c, d] = q.front();
        q.pop();
        visited[a][b][c] = true;
        if (a == m - 1 && b == k - 1) {
            cout << d;
            exit(0);
        }
        if (c < n) {
            for (int i = 0; i < 8; i++) {
                ll dy = a + horse[i][0];
                ll dx = b + horse[i][1];
                if (dy >= 0 && dy < m && dx >= 0 && dx < k && !Map[dy][dx] && !visited[dy][dx][c + 1]) {
                    visited[dy][dx][c + 1] = true;
                    q.push({dy, dx, c + 1, d + 1});
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            ll dy = a + monkey[i][0];
            ll dx = b + monkey[i][1];
            if (dy >= 0 && dy < m && dx >= 0 && dx < k && !Map[dy][dx] && !visited[dy][dx][c]) {
                visited[dy][dx][c] = true;
                q.push({dy, dx, c, d + 1});
            }
        }
    }
}
int main(void) {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cin >> k >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> Map[i][j];
        }
    }
    bfs(0, 0);
    cout << -1;
	return 0;
}