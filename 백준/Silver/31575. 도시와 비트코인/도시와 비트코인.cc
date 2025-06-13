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
    vector<vector<ll>>Map(m + 1, vector<ll>(n + 1));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> Map[i][j];
        }
    }
    queue<pll>q;
    vector<vector<bool>>visited(m + 1, vector<bool>(n + 1, false));
    visited[0][0] = true;
    q.push({ 0, 0 });
    while (!q.empty()) {
        pll temp = q.front();
        q.pop();
        visited[temp.first][temp.second] = true;
        if (temp.first + 1 < m && !visited[temp.first + 1][temp.second] && Map[temp.first + 1][temp.second]) {
            visited[temp.first + 1][temp.second] = true;
            q.push({ temp.first + 1, temp.second });
        }
        if (temp.second + 1 < n && !visited[temp.first][temp.second + 1] && Map[temp.first][temp.second + 1]) {
            visited[temp.first][temp.second + 1] = true;
            q.push({ temp.first, temp.second + 1 });
        }
    }
    if (visited[m - 1][n - 1]) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    return 0;
}