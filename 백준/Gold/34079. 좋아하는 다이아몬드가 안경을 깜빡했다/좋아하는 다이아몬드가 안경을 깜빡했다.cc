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
    cin >> n >> m;
    vector<vector<pll>>graph(n + 1);
    vector<vector<ll>>sortgraph(n + 1);
    priority_queue<pll, vector<pll>, greater<pll>>pq;
    vector<ll>dist(n + 1, LLONG_MAX);
    vector<ll>redist(n + 1, LLONG_MAX);
    for (int i = 0; i < m; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        graph[a].push_back({ b, 1 });
        graph[b].push_back({ a, 1 });
    }
    dist[1] = 0;
    pq.push({ 0, 1 });
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
    pq.push({ 0, n });
    redist[n] = 0;
    while (!pq.empty()) {
        pll temp = pq.top();
        pq.pop();
        if (redist[temp.second] >= temp.first) {
            for (auto& i : graph[temp.second]) {
                if (redist[i.first] > redist[temp.second] + i.second) {
                    redist[i.first] = redist[temp.second] + i.second;
                    pq.push({ redist[i.first], i.first });
                }
            }
        }
    }
    queue<ll>q;
    q.push(1);
    vector<bool>visited(n + 1, false);
    vector<bool>visiteda(n + 1, false);
    while (!q.empty()) {
        ll temp = q.front();
        q.pop();
        visited[temp] = true;
        for (auto& i : graph[temp]) {
            if (!visited[i.first]) {
                visited[i.first] = true;
                q.push(i.first);
            }
            if (dist[temp] + redist[i.first] + 1 == dist[n]) {
                sortgraph[temp].push_back(i.first);
            }
        }
    }
    map<ll, ll>Map;
    map<ll, ll>nMap;
    q.push(1);
    while (!q.empty()) {
        ll temp = q.front();
        q.pop();
        visiteda[temp] = true;
        Map[dist[temp]]++;
        nMap[dist[temp]] = temp;
        for (auto& i : sortgraph[temp]) {
            if (!visiteda[i]) {
                q.push(i);
                visiteda[i] = true;
            } 
        }
    }
    for (auto& i : Map) {
        if (i.second == 1 && i.first != 0 && i.first != dist[n]) {
            cout << nMap[i.first];
            return 0;
        }
    }
    cout << 1;
    return 0;
}