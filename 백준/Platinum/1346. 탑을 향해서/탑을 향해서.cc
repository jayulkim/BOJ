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
    vector<ll>v(n + 2, 0);
    vector<lll>vv(n + 2);
    vector<ll>vvv(n + 2, 0);
    vv[1] = { 0, 0, 1000000 };
    for (int i = 2; i <= n + 1; i++) {
        cin >> v[i] >> get<0>(vv[i]) >> get<1>(vv[i]) >> get<2>(vv[i]);
    }
    vector<vector<ll>>graph(n + 2);
    vector<vector<ll>>topograph(n + 2);
    vector<ll>s;
    vector<ll>visited(n + 2, 0);
    vector<bool>finished(n + 2, false);
    vector<ll>Map(n + 2, 0);
    ll id = 0;
    ll Mapid = 0;
    vector<ll>degree(n + 2, 0);
    function<ll(ll, ll)> getdist = [&](ll aa, ll bb) -> ll {
        auto [a, b, c] = vv[aa];
        auto [d, e, f] = vv[bb];
        if ((d <= a && a <= d + f) || (a <= d && d <= a + c) || (d <= (a + c) && (a + c) <= d + f) || (a <= (d + f) && (d + f) <= a + c)) {
            return llabs(b - e) * llabs(b - e);
        }
        return min({ (a - d) * (a - d) + (b - e) * (b - e), (a + c - d) * (a + c - d) + (b - e) * (b - e), (a - d - f) * (a - d - f) + (b - e) * (b - e), (a + c - d - f) * (a + c - d - f) + (b - e) * (b - e) });
        };
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n + 1; j++) {
            if (getdist(i, j) <= m * m) {
                auto [a, b, c] = vv[i];
                auto [d, e, f] = vv[j];
                if (b >= e) {
                    graph[j].push_back(i);
                }
                if (e >= b) {
                    graph[i].push_back(j);
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
            else {
                degree[Map[i]]++;
            }
        }
        if (parent == visited[start]) {
            Mapid++;
            while (1) {
                ll temp = s.back();
                s.pop_back();
                finished[temp] = true; 
                Map[temp] = Mapid;
                vvv[Mapid] += v[temp];
                if (temp == start) {
                    break;
                }
            }
            if (!s.empty()) {
                degree[Mapid]++;
            }
        }
        return parent;
        };
    for (int i = 1; i <= n + 1; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    for (int i = 1; i <= n + 1; i++) {
        for (auto& j : graph[i]) {
            if (Map[i] != Map[j]) {
                topograph[Map[i]].push_back(Map[j]);
            }
        }
    }
    queue<ll>q;
    vector<ll>dp(n + 2, 0);
    vector<bool>vvvv(n + 2, false);
    for (int i = 1; i <= Mapid; i++) {
        if (!degree[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        ll temp = q.front();
        q.pop();
        if (temp == Map[1]) {
            dp[temp] = vvv[temp];
            vvvv[temp] = true;
        }
        for (auto& i : topograph[temp]) {
            if (--degree[i] == 0) {
                q.push(i);
            }
            if (vvvv[temp]) {
                dp[i] = max(dp[i], dp[temp] + vvv[i]);
                vvvv[i] = true;
            }
        }
    }
    ll Max = 0;
    for (int i = 1; i <= Mapid; i++) {
        Max = max(Max, dp[i]);
    }
    cout << Max;
    return 0;
}