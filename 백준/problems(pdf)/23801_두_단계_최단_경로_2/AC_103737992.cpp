#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define len(str) str.length()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<string, char, ll> scl;
typedef tuple<ll, ll, ll, ll> llll;
typedef tuple<ll, ll, ll, ll, ll> lllll;
typedef tuple<ll, ll, vector<ll>> llv;
typedef tuple<char, ll, ll> cll;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
typedef pair<ll, string> pls;
typedef pair<ll, char> plc;
typedef pair<char, ll> pcl;
typedef pair<ll, vector<ll>> plv;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<ll>dist(n + 1, 1e18);
    vector<ll>redist(n + 1, 1e18);
    priority_queue<pll, vector<pll>, greater<pll>>pq;
    vector<vector<pll>>graph(n + 1);
    for (int i = 0; i < m; i++) {
        ll a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }
    ll s = 0, t = 0;
    cin >> s >> t;
    dist[s] = 0;
    pq.push({ 0, s });
    while (!pq.empty()) {
        auto [a, b] = pq.top();
        pq.pop();
        if (dist[b] >= a) {
            for (auto& i : graph[b]) {
                if (dist[i.first] > dist[b] + i.second) {
                    dist[i.first] = dist[b] + i.second;
                    pq.push({ dist[i.first], i.first });
                }
            }
        }
    }
    redist[t] = 0;
    pq.push({ 0, t });
    while (!pq.empty()) {
        auto [a, b] = pq.top();
        pq.pop();
        if (redist[b] >= a) {
            for (auto& i : graph[b]) {
                if (redist[i.first] > redist[b] + i.second) {
                    redist[i.first] = redist[b] + i.second;
                    pq.push({ redist[i.first], i.first });
                }
            }
        }
    }
    cin >> k;
    ll Min = 1e18;
    for (int i = 0; i < k; i++) {
        ll a = 0;
        cin >> a;
        Min = min(Min, dist[a] + redist[a]);
    }
    if (Min == 1e18) {
        cout << -1;
        return 0;
    }
    cout << Min;
    return 0;
}