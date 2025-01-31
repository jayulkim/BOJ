#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
typedef tuple<pll, string, ll>pllsl;
ll n = 0, m = 0, k = 0;
ll Map[2001][2001];
bool visited[2001][2001];
void bfs(ll y, ll x, char c) {
    ll starty = 0, startx = 0;
    queue<pllsl>q;
    if (c == 'U') {
        starty = 1;
        startx = x / 2 + 1;
        q.push({ { starty, startx }, "down", 1 });
    }
    else if (c == 'D') {
        starty = n;
        startx = x / 2 + 1;
        q.push({ { starty, startx }, "up", 1 });
    }
    else if (c == 'R') {
        starty = y / 2 + 1;
        startx = m;
        q.push({ { starty, startx }, "left", 1 });
    }
    else if (c == 'L') {
        starty = y / 2 + 1;
        startx = 1;
        q.push({ { starty, startx }, "right", 1 });
    }
    visited[starty][startx] = true;
    while (!q.empty()) {
        auto [a, b, c] = q.front();
        q.pop();
        Map[a.first][a.second] = c;
        if (b == "down") {
            if (a.first + 1 <= n && !visited[a.first + 1][a.second]) {
                visited[a.first + 1][a.second] = true;
                q.push({ { a.first + 1, a.second }, b, c + 1 });
            }
            else {
                ll dy = a.first, dx = a.second - 1;
                if (dx >= 1 && !visited[dy][dx]) {
                    visited[dy][dx] = true;
                    q.push({ { dy, dx }, "left", c + 1});
                }
                dx = a.second + 1;
                if (dx <= m && !visited[dy][dx]) {
                    visited[dy][dx] = true;
                    q.push({ { dy, dx }, "right", c + 1 });
                }
            }
        }
        else if (b == "up") {
            if (a.first - 1 >= 1 && !visited[a.first - 1][a.second]) {
                visited[a.first - 1][a.second] = true;
                q.push({ { a.first - 1, a.second }, b, c + 1 });
            }
            else {
                ll dy = a.first, dx = a.second - 1;
                if (dx >= 1 && !visited[dy][dx]) {
                    visited[dy][dx] = true;
                    q.push({ { dy, dx }, "left", c + 1 });
                }
                dx = a.second + 1;
                if (dx <= m && !visited[dy][dx]) {
                    visited[dy][dx] = true;
                    q.push({ { dy, dx }, "right", c + 1 });
                }
            }
        }
        else if (b == "left") {
            if (a.second - 1 >= 1 && !visited[a.first][a.second - 1]) {
                visited[a.first][a.second - 1] = true;
                q.push({ { a.first, a.second - 1 }, b, c + 1 });
            }
            else {
                ll dy = a.first - 1, dx = a.second;
                if (dy >= 1 && !visited[dy][dx]) {
                    visited[dy][dx] = true;
                    q.push({ { dy, dx }, "up", c + 1 });
                }
                dy = a.first + 1;
                if (dy <= n && !visited[dy][dx]) {
                    visited[dy][dx] = true;
                    q.push({ { dy, dx }, "down", c + 1 });
                }
            }
        }
        else if (b == "right") {
            if (a.second + 1 <= m && !visited[a.first][a.second + 1]) {
                visited[a.first][a.second + 1] = true;
                q.push({ { a.first, a.second + 1 }, b, c + 1 });
            }
            else {
                ll dy = a.first - 1, dx = a.second;
                if (dy >= 1 && !visited[dy][dx]) {
                    visited[dy][dx] = true;
                    q.push({ { dy, dx }, "up", c + 1 });
                }
                dy = a.first + 1;
                if (dy <= n && !visited[dy][dx]) {
                    visited[dy][dx] = true;
                    q.push({ { dy, dx }, "down", c + 1 });
                }
            }
        }
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    char c;
    cin >> c;
    bfs(n, m, c);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << Map[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}