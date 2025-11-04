//폰 코딩
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    ll y = 0, x = 0;
    vector<vector<char>>Map(n + 1, vector<char>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> Map[i][j];
            if (Map[i][j] == '2') {
                y = i;
                x = j;
            }
        }
    }
    vector<vector<bool>>visited(n + 1, vector<bool>(m + 1));
    ll Forward[4][2] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
    queue<lll>q;
    visited[y][x] = true;
    q.push({y, x, 0});
    while (!q.empty()) {    
        auto [a, b, c] = q.front();
        q.pop();
        visited[a][b] = true;
        if (Map[a][b] != '0' && Map[a][b] != '2') {
            cout << "TAK" << '\n';
            cout << c;
            return 0;
        }
        for  (int i = 0; i < 4; i++) {
            ll dy = a + Forward[i][0];
            ll dx = b + Forward[i][1];
            if (dy >= 0 && dy < n && dx >= 0 && dx < m && !visited[dy][dx] && Map[dy][dx] != '1') {
                visited[dy][dx] = true;
                q.push({dy, dx, c + 1});
            }
        }
    }
    cout << "NIE";
    return 0;
}