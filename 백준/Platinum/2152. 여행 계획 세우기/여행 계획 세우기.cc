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
    ll start = 0, end = 0;
    cin >> n >> m >> start >> end;
    vector<vector<ll>>graph(n + 1);
    vector<ll>s;
    vector<bool>finished(n + 1, false);
    vector<ll>visited(n + 1, 0);
    ll id = 0;
    vector<ll>v(n + 1, 0);
    vector<ll>degree(n + 1, 0);
    map<ll, ll>Map;
    ll Mapid = 0;
    vector<vector<ll>>topograph(n + 1);
    for (int i = 0; i < m; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        graph[a].push_back(b);
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
            ll count = 0;
            while (1) {
                ll temp = s.back();
                s.pop_back();
                finished[temp] = true;
                Map[temp] = Mapid;
                count++;
                v.push_back(temp);
                if (temp == start) {
                    break;
                }
            }
            v[Mapid] = count;
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
                degree[Map[j]]++;
                topograph[d].push_back(Map[j]);
            }
        }
    }
    vector<ll>dp(n + 1, 0);
    vector<bool>vv(n + 1, false);
    queue<ll>q;
    for (int i = 1; i <= Mapid; i++) {
        if (!degree[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        ll temp = q.front();
        q.pop();
        if (temp == Map[start]) {
            dp[temp] = v[temp];
            vv[temp] = true;
        }
        for (auto& i : topograph[temp]) {
            if (--degree[i] == 0) {
                q.push(i);
            }
            if (vv[temp]) {
                dp[i] = max(dp[i], dp[temp] + v[i]);
                vv[i] = true;
            }
        }
    }
    cout << dp[Map[end]];
    return 0;
}