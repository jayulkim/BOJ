#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<pll>graph[50001];
ll visited[50001];
vector<ll>result(50001, -1);
void bfs(ll start) {
    queue<lll>q;
    q.push({ start, 0, 0 });
    while (!q.empty()) {
        auto [a, b, c] = q.front();
        q.pop();
        visited[a]++;
        if ((a == start && visited[a] == 2) || (a != start && visited[a] == 1)) {
            result[a] = c;
        }
        for (auto& i : graph[a]) {
            if (a == start && visited[a] < n) {
                q.push({ i.first, i.second, c + 1 });
            }
            else if (visited[i.first] < n && llabs(b - i.second) == 1) {
                q.push({ i.first, i.second, c + 1 });
            }
        }
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }
    bfs(1);
    for (int i = 1; i <= n; i++) {
        cout << result[i] << ' ';
    }
    return 0;   
}