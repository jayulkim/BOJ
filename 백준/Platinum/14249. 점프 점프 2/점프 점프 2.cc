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
    cin >> n;
    vector<ll>v(n + 1, 0);
    vector<vector<ll>>graph(n + 1);
    vector<vector<ll>>topograph(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (i - v[i] >= 1) {
            graph[i].push_back(i - v[i]);
        }
        if (i + v[i] <= n) {
            graph[i].push_back(i + v[i]);
        }
    }
    cin >> m;
    vector<ll>s;
    vector<ll>visited(n + 1, 0);
    vector<bool>finished(n + 1, false);
    ll id = 0;
    vector<ll>Map(n + 1);
    ll Mapid = 0;
    vector<ll>degree(n + 1, 0);
    vector<bool>vvv(n + 1, false);
    vector<ll>vv(n + 1, 0);
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
                vv[Mapid]++;
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
    queue<ll>q;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (auto& j : graph[i]) {
            if (Map[i] != Map[j]) {
                topograph[Map[i]].push_back(Map[j]);
            }
        }
    }
    for (int i = 1; i <= Mapid; i++) {
        if (!degree[i]) {
            q.push(i);
        }
    }
    vector<ll>dp(n + 1, 0);
    while (!q.empty()) {
        ll temp = q.front();
        q.pop();
        if (temp == Map[m]) {
            vvv[temp] = true;
            dp[temp] = vv[temp];
        }
        for (auto& i : topograph[temp]) {
            if (--degree[i] == 0) {
                q.push(i);
            }
            if (vvv[temp]) {
                vvv[i] = true;
                dp[i] = max(dp[i], dp[temp] + vv[i]);
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