#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
typedef tuple<pll, string, ll>pllsl;
ll n = 0, m = 0, k = 0;
vector<ll>graph[1000001];
vector<pll>graphgraph[1000001];
bool visited[1000001];
vector<ll>dist(1000001, LLONG_MAX);
bool zombie[1000001];
vector<ll>v;
vector<pll>vv;
void bfs(ll end) {
    queue<pll>q;
    for (auto& i : v) {
        q.push({ i, 0 });
        visited[i] = true;
    }
    while (!q.empty()) {
        pll temp = q.front();
        q.pop();
        visited[temp.first] = true;
        for (auto& i : graph[temp.first]) {
            if (!visited[i] && temp.second + 1 <= end && !zombie[i]) {
                visited[i] = true;
                q.push({ i, temp.second + 1 });
            }
        }
    }
}
void dijkstra(ll start) {
    dist[start] = 0;
    priority_queue<pll, vector<pll>, greater<pll>>pq;
    pq.push({ 0, start });
    while (!pq.empty()) {
        pll temp = pq.top();
        pq.pop();
        if (dist[temp.second] >= temp.first) {
            for (auto& i : graphgraph[temp.second]) {
                if (dist[i.first] > dist[temp.second] + i.second) {
                    dist[i.first] = dist[temp.second] + i.second;
                    pq.push({ dist[i.first], i.first });
                }
            }
        }
    }
}
int main(void) {
    ios::sync_with_stdio(false);             
    cin.tie(0);
    ll a = 0, b = 0;
    cin >> n >> m >> a >> b;
    ll p = 0, q = 0;
    cin >> p >> q;
    for (int i = 0; i < a; i++) {
        ll num = 0;
        cin >> num;
        v.push_back(num);
        zombie[num] = true;
    }
    for (int i = 0; i < m; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        vv.push_back({ a, b });
    }
    bfs(b);
    for (auto& i : vv) {
        if (!zombie[i.first] && !zombie[i.second]) {
            if (visited[i.first]) {
                graphgraph[i.second].push_back({ i.first, q });
            }
            else {
                graphgraph[i.second].push_back({ i.first, p });
            }
            if (visited[i.second]) {
                graphgraph[i.first].push_back({ i.second, q });
            }
            else {
                graphgraph[i.first].push_back({ i.second, p });
            }
        }
    }
    dijkstra(1);
    if (visited[n]) {
        dist[n] -= q;
    }
    else {
        dist[n] -= p;
    }
    cout << dist[n];
    return 0;
}