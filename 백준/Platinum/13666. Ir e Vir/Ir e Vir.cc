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
    while (1) {
        cin >> n >> m;
        if (!n && !m) {
            break;
        }
        vector<vector<ll>>graph(n + 1);
        vector<ll>s;
        vector<ll>visited(n + 1, 0);
        vector<bool>finished(n + 1, false);
        ll count = 0;
        ll id = 0;
        for (int i = 0; i < m; i++) {
            ll a = 0, b = 0, c = 0;
            cin >> a >> b >> c;
            if (c == 1) {
                graph[a].push_back(b);
            }
            else {
                graph[a].push_back(b);
                graph[b].push_back(a);
            }
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
                count++;
                while (1) {
                    ll temp = s.back();
                    s.pop_back();
                    finished[temp] = true;
                    if (temp == start) {
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
        if (count == 1) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }
    return 0;
}