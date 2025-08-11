#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    vector<ll>dista(n + 1, LLONG_MAX);
    vector<ll>distb(n + 1, LLONG_MAX);
    vector<ll>distc(n + 1, LLONG_MAX);
    vector<vector<pll>>graph(n + 1);
    cin >> m;
    for (int i = 0; i < m; i++) {
        ll d = 0, e = 0, f = 0;
        cin >> d >> e >> f;
        graph[d].push_back({ e, f });
        graph[e].push_back({ d, f });
    }
    function<vector<ll>(ll, vector<ll>)> dijkstra = [&](ll start, vector<ll>dist) -> vector<ll> {
        priority_queue<pll, vector<pll>, greater<pll>>pq;
        pq.push({ 0, start });
        dist.resize(n + 1, LLONG_MAX);
        dist[start] = 0;
        while (!pq.empty()) {
            pll temp = pq.top();
            pq.pop();
            if (dist[temp.second] >= temp.first) {
                for (auto& i : graph[temp.second]) {
                    if (dist[i.first] > dist[temp.second] + i.second) {
                        dist[i.first] = dist[temp.second] + i.second;
                        pq.push({ dist[i.first], i.first });
                    }
                }
            }
        }
        return dist;
        };
    dista = dijkstra(a, dista);
    distb = dijkstra(b, distb);
    distc = dijkstra(c, distc);
    ll Max = -1;
    ll result = 0;
    for (int i = 1; i <= n; i++) {
        if (min({ dista[i], distb[i], distc[i] }) > Max) {
            result = i;
            Max = min({ dista[i], distb[i], distc[i] });
        }
    }
    cout << result;
    return 0;
}