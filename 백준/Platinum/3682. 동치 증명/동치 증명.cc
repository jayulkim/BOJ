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
    ll num = 0;
    cin >> num;
    while (num--) {
        cin >> n >> m;
        vector<vector<ll>>graph(n + 1);
        vector<vector<ll>>topograph(n + 1);
        vector<ll>degree(n + 1, 0);
        vector<ll>degreedegree(n + 1, 0);
        vector<ll>visited(n + 1, 0);
        vector<bool>finished(n + 1, false);
        vector<ll>s;
        ll id = 0;
        vector<ll>Map(n + 1);
        ll Mapid = 0;
        for (int i = 0; i < m; i++) {
            ll a = 0, b = 0;
            cin >> a >> b;
            graph[a].push_back(b);
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
            if (visited[start] == parent) {
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
        if (Mapid == 1) {
            cout << 0 << '\n';
            continue;
        }
        for (int i = 1; i <= n; i++) {
            for (auto& j : graph[i]) {
                if (Map[i] != Map[j]) {
                    degreedegree[Map[i]]++;
                    degree[Map[j]]++;
                }
            }
        }
        ll a = 0, b = 0;
        for (int i = 1; i <= Mapid; i++) {
            if (!degree[i]) {
                a++;
            }
            if (!degreedegree[i]) {
                b++;
            }
        }
        cout << max(a, b) << '\n';
    }
    return 0;
}