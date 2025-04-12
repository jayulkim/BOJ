#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<vector<ll>>graph(1000001);
vector<bool>degree(1000001, false);
vector<bool>finished(1000001, false);
vector<ll>visited(1000001, 0);
vector<ll>s;
vector<vector<ll>>scc;
ll id = 0;
ll Mapid = 0;
vector<ll>Map(1000001, 0);
ll dfs(ll start) {
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
        else {
            degree[Map[i]] = true;
        }
    }
    if (parent == visited[start]) {
        vector<ll>v;
        Mapid++;
        while (1) {
            ll temp = s.back();
            s.pop_back();
            finished[temp] = true;
            v.push_back(temp);
            Map[temp] = Mapid;
            if (temp == start) {
                break;
            }
        }
        if (!s.empty()) {
            degree[Mapid] = true;
        }
        scc.push_back(v);
    }
    return parent;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    ll count = 0;
    ll idx = 0;
    for (int i = 1; i <= Mapid; i++) {
        if (!degree[i]) {
            idx = i;
            count++;
        }
    }
    if (count == 1) {
        cout << scc[idx - 1].size() << '\n';
        sort(scc[idx - 1].begin(), scc[idx - 1].end());
        for (auto& i : scc[idx - 1]) {
            cout << i << ' ';
        }
    }
    else {
        cout << 0;
    }
    return 0;
}