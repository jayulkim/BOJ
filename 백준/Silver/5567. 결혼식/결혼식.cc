#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef unsigned long long ull;
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
    vector<bool>visited(n + 1, false);
    for (int i = 0; i < m; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    ll result = 0;
    queue<pll>q;
    q.push({ 1, 0 });
    while (!q.empty()) {
        pll temp = q.front();
        q.pop();
        visited[temp.first] = true;
        if (temp.second <= 2) {
            result++;
            for (auto& i : graph[temp.first]) {
                if (!visited[i]) {
                    q.push({ i, temp.second + 1 });
                    visited[i] = true;
                }
            }
        }
    }
    cout << result - 1;
    return 0;
}