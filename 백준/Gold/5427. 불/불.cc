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
    ll num = 0;
    cin >> num;
    while (num--) {
        cin >> m >> n;
        priority_queue<llll, vector<llll>, greater<llll>>pq;
        vector<vector<ll>>Forward = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
        vector<vector<char>>Map(n + 1, vector<char>(m + 1));
        vector<vector<ll>>visited(n + 1, vector<ll>(m + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> Map[i][j];
                if (Map[i][j] == '*') {
                    pq.push({ 1, 0, i, j });
                }
                else if (Map[i][j] == '@') {
                    pq.push({ 1, 1, i, j });
                }
            }
        }
        bool find = false;
        while (!pq.empty()) {
            auto [a, b, c, d] = pq.top();
            pq.pop();
            visited[c][d] = a;
            for (int i = 0; i < 4; i++) {
                ll dy = c + Forward[i][0];
                ll dx = d + Forward[i][1];
                if (dy >= 0 && dy < n && dx >= 0 && dx < m) {
                    if (!visited[dy][dx] && Map[dy][dx] != '#') {
                        visited[dy][dx] = a + 1;
                        pq.push({ a + 1, b, dy, dx });
                    }
                }
                else if (b) {
                    cout << a << '\n';
                    find = true;
                    break;
                }
            }
            if (find) {
                break;
            }
        }
        if (!find) {
            cout << "IMPOSSIBLE" << '\n';
        }
    }
    return 0; 
}