//폰 코딩
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
    vector<ll>a(n + 1);
    vector<ll>b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    vector<vector<pll>>graph(n + 2);
    for (int i = 1; i <= n; i++) {
        if (i - a[i] < 1) {
            graph[0].push_back({i, b[i]});
        }
        else {
            graph[i - a[i]].push_back({i, b[i]});
        }
        if (i + a[i] > n) {
            graph[0].push_back({i, b[i]});
        }
        else {
            graph[i + a[i]].push_back({i, b[i]});
        }
    }
    priority_queue<pll, vector<pll>, greater<pll>>pq;
    vector<ll>dist(n + 2, LLONG_MAX);
    dist[0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        pll temp = pq.top();
        pq.pop();
        if (dist[temp.second] >= temp.first) {
            for (auto& i : graph[temp.second]) {
                if (dist[i.first] > dist[temp.second] + i.second) {
                    dist[i.first] = dist[temp.second] + i.second;
                    pq.push({dist[i.first], i.first});
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
    }
    return 0;
}