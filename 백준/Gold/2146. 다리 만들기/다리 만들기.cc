#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll Map[101][101];
vector<pll>graph[10001];
vector<pll>v[10001];
bool visited[101][101];
bool vv[101][101];
ll Forward[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
ll idx = 0;
void bfs(ll y, ll x) {
    visited[y][x] = true;
    queue<pll>q;
    q.push({ y, x });
    while (!q.empty()) {
        pll temp = q.front();
        q.pop(); 
        visited[temp.first][temp.second] = true;
        graph[idx].push_back({ temp.first, temp.second });
        for (int i = 0; i < 4; i++) {
            ll dy = temp.first + Forward[i][0];
            ll dx = temp.second + Forward[i][1];
            if (dy >= 0 && dy < n && dx >= 0 && dx < n && !visited[dy][dx] && Map[dy][dx]) {
                visited[dy][dx] = true;
                q.push({ dy, dx });
            }
        }
    }
    idx++;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> Map[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && Map[i][j]) {
                bfs(i, j);
            }
        }
    }
    for (int i = 0; i < idx; i++) {
        for (auto& j : graph[i]) {
            for (int k = 0; k < 4; k++) {
                ll dy = j.first + Forward[k][0];
                ll dx = j.second + Forward[k][1];
                if (dy >= 0 && dy < n && dx >= 0 && dx < n && !Map[dy][dx] && !vv[dy][dx]) {
                    vv[dy][dx] = true;
                    v[i].push_back({ dy, dx });
                }
            }
        }
        memset(vv, false, sizeof(vv));
    }
    ll Min = LLONG_MAX;
    for (int i = 0; i < idx - 1; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            ll y = v[i][j].first;
            ll x = v[i][j].second;
            for (int k = i + 1; k < idx; k++) {
                for (auto& u : v[k]) {
                    Min = min(Min, llabs(y - u.first) + llabs(x - u.second) + 1);
                }
            }
        }
    }
    cout << Min;
    return 0;
}