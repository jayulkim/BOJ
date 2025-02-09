#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
typedef tuple<pll, string, ll>pllsl;
ll n = 0, m = 0, k = 0;
vector<pll>graph[200001];
vector<ll>dist(200001, LLONG_MAX);
vector<ll>reversedist(200001, LLONG_MAX);
void dijkstra(ll start) {
    priority_queue<pll, vector<pll>, greater<pll>>pq;
    dist[start] = 0;
    pq.push({ 0, start });
    while (!pq.empty()) {
        pll temp = pq.top();
        pq.pop();
        if (dist[temp.second] >= temp.first) {
            for (auto& i : graph[temp.second]) {
                if (dist[i.second] > dist[temp.second] + i.first) {
                    dist[i.second] = dist[temp.second] + i.first;
                    pq.push({ dist[i.second], i.second });
                }
            }
        }
    }
}
void reversedijkstra(ll start) {
    priority_queue<pll, vector<pll>, greater<pll>>pq;
    reversedist[start] = 0;
    pq.push({ 0, start });
    while (!pq.empty()) {
        pll temp = pq.top();
        pq.pop();
        if (reversedist[temp.second] >= temp.first) {
            for (auto& i : graph[temp.second]) {
                if (reversedist[i.second] > reversedist[temp.second] + i.first) {
                    reversedist[i.second] = reversedist[temp.second] + i.first;
                    pq.push({ reversedist[i.second], i.second });
                }
            }
        }
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll start = 0, end = 0;
    cin >> n >> m >> start >> end;
    for (int i = 0; i < m; i++) {
        ll a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        graph[a].push_back({ c, b });
        graph[b].push_back({ c, a });
    }
    dijkstra(start);
    reversedijkstra(end);
    vector<ll>result;
    for (int i = 1; i <= n; i++) {
        if (dist[i] + reversedist[i] == dist[end]) {
            result.push_back(i);
        }
    }
    cout << result.size() << '\n';
    for (auto& i : result) {
        cout << i << ' ';
    }
    return 0;
}