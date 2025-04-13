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
    ll num = 0;
    cin >> num;
    while (num--) {
        cin >> n >> m;
        vector<vector<ll>>Map(n + 1, vector<ll>(m + 1));
        vector<pll>Forward = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
        vector<vector<ll>>graph((n + 1) * (m + 1) + 1);
        vector<ll>s;
        vector<vector<ll>>pos(n + 1, vector<ll>(m + 1, 0));
        ll posid = 0;
        vector<ll>visited((n + 1) * (m + 1) + 1, 0);
        vector<bool>finished((n + 1) * (m + 1) + 1, 0);
        ll id = 0;
        vector<ll>idMap((n + 1) * (m + 1) + 1, 0);
        ll Mapid = 0;
        vector<ll>indegree((n + 1) * (m + 1) + 1, 0);
        vector<ll>outdegree((n + 1) * (m + 1) + 1, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> Map[i][j];
                pos[i][j] = ++posid;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < 4; k++) {
                    ll dy = i + Forward[k].first;
                    ll dx = j + Forward[k].second;
                    if (dy >= 0 && dy < n && dx >= 0 && dx < m && Map[i][j] >= Map[dy][dx]) {
                        graph[pos[i][j]].push_back(pos[dy][dx]);
                    }
                }
            }
        }
        function<ll(ll)> dfs = [&](ll start) -> ll {
            visited[start] = ++id;
            s.push_back(start);
            ll parent = visited[start];
            for (auto& i : graph[start]) {
                if (!visited[i]) {
                    parent = min(parent, dfs(i));
                }
                else if (!finished[i]) {
                    parent = min(parent, visited[i]);
                }
            }
            if (parent == visited[start]) {
                Mapid++;
                while (1) {
                    ll temp = s.back();
                    s.pop_back();
                    finished[temp] = true;
                    idMap[temp] = Mapid;
                    if (start == temp) {
                        break;
                    }
                }
            }
            return parent;
            };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[pos[i][j]]) {
                    dfs(pos[i][j]);
                }
            }
        }
        if (Mapid == 1) {
            cout << 0 << '\n';
            continue;
        }
        for (int i = 1; i <= n * m; i++) {
            for (auto& j : graph[i]) {
                if (idMap[i] != idMap[j]) {
                    outdegree[idMap[i]]++;
                    indegree[idMap[j]]++;
                }
            }
        }
        ll a = 0, b = 0;
        for (int i = 1; i <= Mapid; i++) {
            if (!indegree[i]) {
                a++;
            }
            if (!outdegree[i]) {
                b++;
            }
        }
        cout << max(a, b) << '\n';
    }
    return 0;
}