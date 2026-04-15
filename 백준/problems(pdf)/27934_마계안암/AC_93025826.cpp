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
    vector<vector<pll>>graph(n + 1);
    vector<vector<ll>>topograph(n + 1);
    vector<vector<pll>>dijkgraph(n + 1);
    vector<ll>degree(n + 1, 0);
    priority_queue<pll, vector<pll>, greater<pll>>pq;
    vector<ll>dist(n + 1, LLONG_MAX);
    vector<ll>s;
    map<ll, ll>Map;
    map<ll, ll>infMap;
    ll id = 0;
    ll Mapid = 0;
    vector<ll>visited(n + 1, 0);
    vector<bool>finished(n + 1, false);
    map<pll, ll>zero;
    vector<lll>v;
    vector<vector<ll>>scc;
    for (int i = 0; i < m; i++) {
        ll a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        graph[a].push_back({ c, b });
        v.push_back({ a, b, c });
        if (!c) {
            zero[{a, b}]++;
        }
    }
    function<ll(ll)> dfs = [&](ll start) -> ll {
        visited[start] = ++id;
        s.push_back(start);
        ll parent = visited[start];
        for (auto& i : dijkgraph[start]) {
            if (!visited[i.first]) {
                parent = min(parent, dfs(i.first));
            }
            else if (!finished[i.first]) {
                parent = min(parent, visited[i.first]);
            }
        }
        if (parent == visited[start]) {
            vector<ll>v;
            Mapid++;
            while (1) {
                ll temp = s.back();
                s.pop_back();
                finished[temp] = true;
                Map[temp] = Mapid;
                v.push_back(temp);
                if (start == temp) {
                    break;
                }
            }
            scc.push_back(v);
        }
        return parent;
        };
    dist[1] = 0;
    pq.push({ 0, 1 });
    while (!pq.empty()) {
        pll temp = pq.top();
        pq.pop();
        if (dist[temp.second] >= temp.first) {
            for (auto& i : graph[temp.second]) {
                if (dist[i.second] > dist[temp.second] + i.first) {
                    dist[i.second] = dist[temp.second] + i.first;
                    pq.push({ dist[i.second], i.second });
                }
            }
        }
    }
    for (auto& [a, b, c] : v) {
        if (dist[b] == dist[a] + c) {
            dijkgraph[a].push_back({ b, c });
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    for (int i = 1; i <= Mapid; i++) {
        if (scc[i - 1].size() > 1) {
            ll sum = 0;
            for (auto& j : scc[i - 1]) {
                for (auto& k : dijkgraph[j]) {
                    if (i == Map[k.first]) {
                        sum += k.second;
                    }
                }
            }
            if (!sum) {
                infMap[i]++;
            }
        }
    }
    for (auto& [a, b, c] : v) {
        if (a == b && !c) {
            infMap[Map[a]]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        ll d = Map[i];
        for (auto& j : dijkgraph[i]) {
            if (d != Map[j.first]) {
                topograph[d].push_back(Map[j.first]);
                degree[Map[j.first]]++;
            }
        }
    }
    function<ll(ll, ll)> addmod = [&](ll x, ll y) -> ll {
        if (x >= 998244353 - y) {
            return x - (998244353 - y);
        }
        return x + y;
        };
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
        if (temp == Map[1]) {
            dp[temp] = 1;
            vv[temp] = true;
        }
        if (infMap[temp]) {
            dp[temp] = -1;
        }
        for (auto& i : topograph[temp]) {
            if (--degree[i] == 0) {
                q.push(i);
            }
            if (dp[temp] == -1) {
                dp[i] = -1;
            }
            else if (vv[temp] && dp[i] != -1) {
                dp[i] = addmod(dp[i], dp[temp]);
                vv[i] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dp[Map[i]] << '\n';
    }
    return 0;
}