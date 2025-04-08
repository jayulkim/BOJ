#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<vector<ll>>graphgraph(1000001);
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<vector<pll>>graph(n + 1);
    vector<map<ll, ll>>Map(n + 1);
    map<pll, ll>v;
    map<ll, ll>vv;
    ll idx = 0;
    for (int i = 0; i < m; i++) {
        ll a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        graph[a].push_back({ c, b });
        graph[b].push_back({ c, a });
        Map[a][c]++;
        Map[b][c]++;
    }
    v[{1, 0}] = ++idx;
    queue<pll>q;
    q.push({ v[{1, 0}], 0});
    for (auto& i : graph[1]) {
        if (!v[{i.second, i.first}]) {
            v[{i.second, i.first}] = ++idx;
            vv[idx] = i.second;
        }
        graphgraph[v[{1, 0}]].push_back(v[{i.second, i.first}]);
        q.push({ v[{ i.second, i.first }], 1 });
    }
    for (int i = 2; i <= n; i++) {
        for (auto& j : graph[i]) {
            if (j.first + 1 <= 100000 && Map[i][j.first + 1]) {
                if (!v[{i, j.first + 1}]) {
                    v[{i, j.first + 1}] = ++idx;
                    vv[idx] = i;
                }
                if (!v[{ j.second, j.first }]) {
                    v[{ j.second, j.first }] = ++idx;
                    vv[idx] = j.second;
                }
                graphgraph[v[{i, j.first + 1}]].push_back(v[{ j.second, j.first }]);
            }
            if (j.first - 1 >= 1 && Map[i][j.first - 1]) {
                if (!v[{i, j.first - 1}]) {
                    v[{i, j.first - 1}] = ++idx;
                    vv[idx] = i;
                }
                if (!v[{ j.second, j.first }]) {
                    v[{ j.second, j.first }] = ++idx;
                    vv[idx] = j.second;
                }
                graphgraph[v[{i, j.first - 1}]].push_back(v[{ j.second, j.first }]);
            }
        }
    }
    vector<bool>visited(idx + 1, false);
    vector<ll>result(n + 1, LLONG_MAX);
    while (!q.empty()) {
        pll temp = q.front();
        q.pop();
        if (!visited[temp.first]) {
            result[vv[temp.first]] = min(result[vv[temp.first]], temp.second);
            visited[temp.first] = true;
            for (auto& i : graphgraph[temp.first]) {
                if (!visited[i]) {
                    q.push({ i, temp.second + 1 });
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (result[i] == LLONG_MAX) {
            cout << -1 << ' ';
        }
        else {
            cout << result[i] << ' ';
        }
    }
    return 0;
}