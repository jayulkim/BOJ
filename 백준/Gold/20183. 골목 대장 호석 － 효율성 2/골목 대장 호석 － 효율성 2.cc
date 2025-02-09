#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll a = 0, b = 0;
vector<pll>graph[100001];
vector<ll>dist(100001, LLONG_MAX);
ll dijkstra(ll start, ll mid) {
    ll result = 0;
    dist[start] = 0;
    priority_queue<pll, vector<pll>, greater<pll>>pq;
    pq.push({ 0, start });
    while(!pq.empty()) {
        pll temp = pq.top();
        pq.pop();
        if (dist[temp.second] >= temp.first) {
            for (auto& i : graph[temp.second]) {
                if (i.first <= mid && dist[i.second] > dist[temp.second] + i.first) {
                    dist[i.second] = dist[temp.second] + i.first;
                    pq.push({ dist[i.second], i.second });
                    result = max(result, i.first);
                }
            }
        }
    }
    return result;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k >> a >> b;
    for (int i = 0; i < m; i++) {
        ll a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        graph[a].push_back({ c, b });
        graph[b].push_back({ c, a });
    }
    ll start = 1, end = 1e9, mid = 0;
    ll Min = LLONG_MAX;
    while (start <= end) {
        mid = (start + end) / 2;
        ll result = dijkstra(k, mid);
        if (dist[a] <= b) {
            end = mid - 1;
            Min = min(Min, min(mid, result));
        }
        else {
            start = mid + 1;
        }
        vector<ll>(100001, LLONG_MAX).swap(dist);
    }
    if (Min == LLONG_MAX) {
        cout << -1;
        return 0;
    }
    cout << Min;
    return 0;
}