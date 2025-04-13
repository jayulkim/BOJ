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
    vector<vector<ll>>graph(n + 1);
    vector<ll>visited(n + 1, 0);
    vector<bool>finished(n + 1, false);
    vector<bool>degree(n + 1, false);
    vector<ll>Map(n + 1, 0);
    ll Mapid = 0;
    ll id = 0;
    vector<ll>s;
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
        for (auto& j : graph[i]) {
            if (Map[i] != Map[j]) {
                degree[Map[i]] = true;
            }
        }
    }
    ll count = 0;
    ll idx = 0;
    for (int i = 1; i <= Mapid; i++) {
        if (!degree[i]) {
            count++;
            idx = i;
        }
    }
    if (count == 1) {
        ll c = 0;
        for (int i = 1; i <= n; i++) {
            if (Map[i] == idx) {
                c++;
            }
        }
        cout << c;
    }
    else {
        cout << 0;
    }
    return 0;
}