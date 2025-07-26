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
    vector<vector<ll>>Forward = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
    vector<vector<ll>>visited(n + 1, vector<ll>(m + 1, 0));
    vector<vector<ll>>t(n + 1, vector<ll>(m + 1, 0));
    priority_queue<llll, vector<llll>, greater<llll>>pq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> Map[i][j];
            if (Map[i][j]) {
                pq.push({0, Map[i][j], i, j});
                visited[i][j] = Map[i][j];
            }
        }
    }
    while (!pq.empty()) {
        auto [a, b, c, d] = pq.top();
        pq.pop();
        t[c][d] = a;
        if (visited[c][d] != 3) {
            if (b == 1) {
                for (int i = 0; i < 4; i++) {
                    ll dy = c + Forward[i][0];
                    ll dx = d + Forward[i][1];
                    if (dy < n && dy >= 0 && dx < m && dx >= 0 && !Map[dy][dx] && !visited[dy][dx]) {
                        visited[dy][dx] = 1;
                        pq.push({ a + 1, 1, dy, dx });
                        t[dy][dx] = a + 1;
                    }
                }
            }
            else if (b == 2) {
                for (int i = 0; i < 4; i++) {
                    ll dy = c + Forward[i][0];
                    ll dx = d + Forward[i][1];
                    if (dy < n && dy >= 0 && dx < m && dx >= 0 && !Map[dy][dx]) {
                        if (visited[dy][dx] == 1 && t[dy][dx] == a + 1) {
                            visited[dy][dx] = 3;
                        }
                        else if (!visited[dy][dx]) {
                            visited[dy][dx] = 2;
                            pq.push({ a + 1, 2, dy, dx });
                        }
                    }
                }
            }
        }
    }
    ll a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == 1) {
                a++;
            }
            else if (visited[i][j] == 2) {
                b++;
            }
            else if (visited[i][j] == 3) {
                c++;
            }
        }
    }
    cout << a << ' ' << b << ' ' << c;
    return 0;
 } 