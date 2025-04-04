#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll id = 0;
ll visited[100001];
vector<ll>graph[100001];
vector<ll>s;
bool finished[100001];
map<ll, ll>Map;
bool degree[100001];
ll Mapid = 0;
map<pll, ll>graphMap;
ll dfs(ll start) {
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
            Map[temp] = Mapid;
            finished[temp] = true;
            if (start == temp) {
                break;
            }
        }
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
        if (!graphMap[{a, b}]) {
            graph[a].push_back(b);
            graphMap[{a, b}]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        ll d = Map[i];
        for (auto& j : graph[i]) {
            if (d != Map[j]) {
                degree[Map[j]] = true;
            }
        }
    }
    ll result = 0;
    for (int i = 1; i <= Mapid; i++) {
        if (!degree[i]) {
            result++;
        }
    }
    cout << result;
    return 0;
}