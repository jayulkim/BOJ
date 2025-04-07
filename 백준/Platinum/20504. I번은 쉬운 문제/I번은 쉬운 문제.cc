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
    vector<vector<ll>>graph(n + 1, vector<ll>());
    vector<bool>finished(n + 1, false);
    vector<ll>visited(n + 1, 0);
    vector<ll>degree(n + 1, 0);
    vector<ll>s;
    ll id = 0;
    map<ll, ll>Map;
    ll Mapid = 0;
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
                Map[temp] = Mapid;
                finished[temp] = true;
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
                degree[Map[j]]++;
            }
        }
    }
    ll count = 0;
    for (int i = 1; i <= Mapid; i++) {
        if (!degree[i]) {
            count++;
        }
    }
    map<ll, ll>a;
    cin >> k;
    ll result = 0;
    for (int i = 0; i < k; i++) {
        ll num = 0;
        cin >> num;
        if (!a[Map[num]] && !degree[Map[num]]) {
            a[Map[num]]++;
            result++;
        }
    }
    if (count == result) {
        cout << result;
    }
    else {
        cout << -1;
    }
    return 0;   
}