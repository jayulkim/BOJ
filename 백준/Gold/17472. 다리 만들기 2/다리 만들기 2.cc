#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
typedef tuple<pll, string, ll>pllsl;
ll n = 0, m = 0, k = 0;
ll Map[11][11];
bool visited[11][11];
priority_queue<tp, vector<tp>, greater<tp>>pq;
ll parent[7];
ll Forward[4][2] = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };
vector<pll>graph[7];
vector<pll>v[7];
ll idx = 1;
void bfs(ll y, ll x) {
    visited[y][x] = true;
    queue<pll>q;
    q.push({ y, x });
    while (!q.empty()) {
        pll temp = q.front();
        q.pop();
        graph[idx].push_back({ temp.first, temp.second });
        visited[temp.first][temp.second] = true;
        Map[temp.first][temp.second] = idx;
        for (int i = 0; i < 4; i++) {
            ll dy = temp.first + Forward[i][0];
            ll dx = temp.second + Forward[i][1];
            if (dy >= 0 && dy < n && dx >= 0 && dx < m && !visited[dy][dx] && Map[dy][dx]) {
                visited[dy][dx] = true;
                q.push({ dy, dx });
            }
        }
    }
    idx++;
}
ll getparent(ll x) {
    if (x == parent[x]) {
        return x;
    }
    return parent[x] = getparent(parent[x]);
}
void merge(ll a, ll b) {
    a = getparent(a);
    b = getparent(b);
    if (a < b) {
        parent[b] = a;
    }
    else {
        parent[a] = b;
    }
}
ll kruskal(ll n) {
    ll result = 0, count = 0;
    while (!pq.empty() && count < n - 1) {
        auto [a, b, c] = pq.top();
        pq.pop();
        if (getparent(b) != getparent(c)) {
            count++;
            merge(b, c);
            result += a;
        }
    }
    if (count < n - 1) {
        return -1;
    }
    return result;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> Map[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && Map[i][j]) {
                bfs(i, j);
            }
        }
    }
    for (int i = 1; i < idx; i++) {
        for (auto& j : graph[i]) {
            for (int k = 0; k < 4; k++) {
                ll dy = j.first + Forward[k][0];
                ll dx = j.second + Forward[k][1];
                if (dy >= 0 && dy < n && dx >= 0 && dx < m && !Map[dy][dx]) {
                    v[i].push_back({ dy, dx });
                }
            }
        }
    }
    for (int i = 1; i < idx - 1; i++) {
        for (int j = i + 1; j < idx; j++) {
            for (int k = 0; k < v[i].size(); k++) {
                for (int u = 0; u < v[j].size(); u++) {
                    if ((v[i][k].first == v[j][u].first || v[i][k].second == v[j][u].second) && llabs(v[i][k].first - v[j][u].first) + llabs(v[i][k].second - v[j][u].second) + 1 >= 2) {
                        vector<pair<pll, ll>>a;
                        vector<pair<pll, ll>>b;
                        for (int l = 0; l < 4; l++) {
                            ll dy = v[i][k].first + Forward[l][0];
                            ll dx = v[i][k].second + Forward[l][1];
                            if (dy >= 0 && dy < n && dx >= 0 && dx < m && Map[dy][dx] == i) {
                                a.push_back({ { dy, dx }, l });
                            }
                            dy = v[j][u].first + Forward[l][0];
                            dx = v[j][u].second + Forward[l][1];
                            if (dy >= 0 && dy < n && dx >= 0 && dx < m && Map[dy][dx] == j) {
                                b.push_back({ { dy, dx }, l });
                            }
                        }
                        bool find = false;
                        for (auto& l : a) {
                            for (auto& h : b) {
                                if ((l.first.first == h.first.first || l.first.second == h.first.second) && ((l.second == 0 && h.second == 1) || (l.second == 1 && h.second == 0) || (l.second == 2 && h.second == 3) || (l.second == 3 && h.second == 2))) {
                                    find = true;
                                    break;
                                }
                            }
                            if (find) {
                                break;
                            }
                        }
                        if (find) {
                            bool a = false;
                            if (v[i][k].first == v[j][u].first) {
                                for (int l = min(v[i][k].second, v[j][u].second); l <= max(v[i][k].second, v[j][u].second); l++) {
                                    if (Map[v[i][k].first][l]) {
                                        a = true;
                                        break;
                                    }
                                }
                            }
                            else if (v[i][k].second == v[j][u].second) {
                                for (int l = min(v[i][k].first, v[j][u].first); l <= max(v[i][k].first, v[j][u].first); l++) {
                                    if (Map[l][v[i][k].second]) {
                                        a = true;
                                        break;
                                    }
                                }
                            }
                            if (!a) {
                                pq.push({ llabs(v[i][k].first - v[j][u].first) + llabs(v[i][k].second - v[j][u].second) + 1, i, j });
                            }
                        }          
                    }
                }
            }
        }
    }
    for (int i = 1; i < idx; i++) {
        parent[i] = i;
    }
    cout << kruskal(idx - 1);
    return 0;
}