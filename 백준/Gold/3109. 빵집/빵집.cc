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
    vector<vector<char>>Map(n + 1, vector<char>(m + 1));
    vector<vector<bool>>visited(n + 1, vector<bool>(m + 1, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> Map[i][j];
        }
    }
    map<ll, ll>mm;
    vector<vector<ll>>forward = { {-1, 1}, {0, 1}, {1, 1} };
    function<bool(ll, ll, ll)> dfs = [&](ll y, ll x, ll temp) -> bool {
        if (mm[temp]) {
            return true;
        }
        visited[y][x] = true;
        if (x == m - 1) {
            mm[temp]++;
            return true;
        }
        bool find = false;
        for (int i = 0; i < 3; i++) {
            ll dy = y + forward[i][0];
            ll dx = x + forward[i][1];
            if (dy >= 0 && dy < n && dx >= 0 && dx < m) {
                if (!visited[dy][dx] && Map[dy][dx] != 'x') {
                    find |= dfs(dy, dx, temp);
                }
            }
        }
        return find;
        };
    ll result = 0;
    for (int i = 0; i < n; i++) {
        result += dfs(i, 0, i + 1);
    }
    cout << result;
    return 0; 
}