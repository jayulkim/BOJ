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
    while (1) {
        cin >> n;
        if (!n) {
            break;
        }
        cin >> m;
        vector<bool>vv(n + 1, false);
        vector<vector<ll>>graph(n + 1, vector<ll>());
        vector<vector<ll>>topograph(n + 1, vector<ll>());
        for (int i = 0; i < m; i++) {
            ll a = 0, b = 0;
            cin >> a >> b;
            graph[a].push_back(b);
            if (a != b) {
                vv[a] = true;
            }
        }
        vector<ll>s;
        vector<ll>result;
        vector<bool>finished(n + 1, false);
        vector<ll>visited(n + 1, 0);
        ll id = 0;
        ll Mapid = 0;
        map<ll, ll>Map;
        vector<ll>degree(n + 1, 0);
        map<ll, ll>a;
        for (int i = 1; i <= n; i++) {
            if (!vv[i]) {
                result.push_back(i);
            }
        }
        function<ll(ll)> dfs = [&](ll start) -> ll {
            visited[start] = ++id;
            ll parent = visited[start];
            s.push_back(start);
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
                    Map[temp] = Mapid;
                    if (start == temp) {
                        break;
                    }
                }
            }
            return parent;
            };
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        for (int i = 1; i <= n; i++) {
            ll d = Map[i];
            for (auto& j : graph[i]) {
                if (d != Map[j]) {
                    topograph[Map[i]].push_back(Map[j]);
                    degree[Map[j]]++;
                }
            }
        }
        queue<pll>q;
        for (int i = 1; i <= Mapid; i++) {
            if (!degree[i]) {
                q.push({i, 0});
            }
        }
        ll Max = 0;
        while (!q.empty()) {
            pll temp = q.front();
            q.pop();
            a[temp.first] = temp.second;
            Max = max(Max, temp.second);
            for (auto& i : topograph[temp.first]) {
                if (--degree[i] == 0) {
                    q.push({ i, temp.second + 1 });
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (a[Map[i]] == Max && vv[i]) {
                result.push_back(i);
            }
        }
        sort(result.begin(), result.end());
        for (auto& i : result) {
            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}