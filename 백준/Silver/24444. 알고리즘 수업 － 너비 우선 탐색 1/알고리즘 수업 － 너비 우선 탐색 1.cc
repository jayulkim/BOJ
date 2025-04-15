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
    cin >> n >> m >> k;
    vector<vector<ll>>graph(n + 1);
    for (int i = 0; i < m; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    queue<ll>q;
    vector<ll>visited(n + 1, 0);
    q.push(k);
    ll count = 1;
    while (!q.empty()) {
        ll temp = q.front();
        q.pop();
        visited[temp] = count++;
        for (auto& i : graph[temp]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = count;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << visited[i] << '\n';
    }
    return 0;
}