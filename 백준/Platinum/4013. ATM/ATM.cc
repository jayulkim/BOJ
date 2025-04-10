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
    vector<ll>v(n + 1);
    vector<vector<ll>>graph(n + 1);
    vector<vector<ll>>topograph(n + 1);
    vector<ll>s;
    map<ll, ll>Map;
    ll id = 0;
    ll Mapid = 0;
    vector<ll>visited(n + 1, 0);
    vector<bool>finished(n + 1, false);
    ll start = 0;
    map<ll, ll>vv;
    vector<ll>vvv(n + 1);
    vector<ll>degree(n + 1, 0);
    for (int i = 0; i < m; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
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
            ll sum = 0;
            while (1) {
                ll temp = s.back();
                s.pop_back();
                sum += v[temp];
                Map[temp] = Mapid;
                finished[temp] = true;
                if (start == temp) {
                    break;
                }
            }
            vvv[Mapid] = sum;
        }
        return parent;
        };
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    cin >> start >> k;
    for (int i = 0; i < k; i++) {
        ll num = 0;
        cin >> num;
        vv[Map[num]]++;
    }
    ll Max = 0;
    for (int i = 1; i <= n; i++) {
        ll d = Map[i];
        for (auto& j : graph[i]) {
            if (d != Map[j]) {
                topograph[d].push_back(Map[j]);
                degree[Map[j]]++;
            }
        }
    }
    vector<ll>dp(n + 1, 0);
    vector<bool>vvvv(n + 1, false);
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
    for (auto& i : vv) {
        Max = max(Max, dp[i.first]);
    }
    cout << Max;
    return 0;
}